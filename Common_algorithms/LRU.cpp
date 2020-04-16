#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template<class K, class T>
struct LRUCacheEntry{
    K key;
    T data;
    LRUCacheEntry* prev;
    LRUCacheEntry* next;
};

template<class K, class T>
class LRUCache{
private:
    unordered_map< K, LRUCacheEntry<K, T>*> mapper;
    vector<LRUCacheEntry<K,T>*> freeEntries;
    LRUCacheEntry<K,T>* head;
    LRUCacheEntry<K,T>* tail;
    LRUCacheEntry<K,T>* entries;
public:
    LRUCache(size_t size){
        entries = new LRUCacheEntry<K,T>[size];
        for(int i = 0; i < size; i++){
            freeEntries.push_back(entries+i);
        }
        head = new LRUCacheEntry<K,T>;
        tail = new LRUCacheEntry<K,T>;
        head->prev = nullptr;
        head->next = tail;
        tail->next = nullptr;
        tail->prev = head;
    }

    ~LRUCache(){
        delete head;
        delete tail;
        delete[] entries;
    }

    void put(K key, T data){
        LRUCacheEntry<K,T>* node = mapper[key];
        if(node){
            detach(node);
            node->data = data;
            attach(node);
        }else{
            if(freeEntries.empty()){
                node = tail->prev;
                detach(node);
                mapper.erase(node->key);
                node->data = data;
                node->key = key;
                mapper[key] = node;
                attach(node);
            } else {
                node = freeEntries.back();
                freeEntries.pop_back();
                node->key = key;
                node->data = data;
                mapper[key] = node;
                attach(node);
            }
        }
    }
    T get(K key){
        LRUCacheEntry<K,T>* node = mapper[key];
        if(node) {
            detach(node);
            attach(node);
            return node->data;
        }
        else return -1;
    }
private:
    void detach(LRUCacheEntry<K,T>* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void attach(LRUCacheEntry<K,T>* node){
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
};

int main(){
    LRUCache <int, int>cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cout << cache.get(1) << endl;
    cache.put(3,3);
    cout << cache.get(2) << endl;

    cache.put(4,4);
    cout << cache.get(1) << endl;

    cout << cache.get(3) << endl;

    cout << cache.get(4) << endl; 
    return 0;
}