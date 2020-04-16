#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <class K, class T>
struct LRUCachenode{
    K key;
    T value;
    LRUCachenode* prev;
    LRUCachenode* next;
};

template <class K, class T>
class LRUCache{
    private:
        unordered_map<K, LRUCachenode<K,T>*> maper;
        vector<LRUCachenode<K,T>*> freenodes;
        LRUCachenode<K,T>* head;
        LRUCachenode<K,T>* tail;
        LRUCachenode<K,T>* nodes;
    public:
        LRUCache(size_t size){
            nodes = new LRUCachenode<K,T>[size];
            for(int i = 0; i < size; i++){
                freenodes.push_back(nodes + i);
            }
            head = new LRUCachenode<K,T>;
            tail = new LRUCachenode<K,T>;
            head->prev = nullptr;
            tail->prev = head;
            head->next = tail;
            tail->next = nullptr;
        }

        ~LRUCache(){
            delete head;
            delete tail;
            delete[] nodes;
        }

        void put(K key, T value){
            LRUCachenode<K,T>* node = maper[key];
            if(node){
                detach(node);
                node->value = value;
                attach(node);
            }else{
                if(freenodes.empty()){
                    node = tail->prev;
                    detach(node);
                    maper.erase(node->key);
                    node->key = key;
                    node->value = value;
                    maper[key] = node;
                    attach(node);
                }else{
                    node = freenodes.back();
                    freenodes.pop_back();
                    node->key = key;
                    node->value = value;
                    maper[key] = node;
                    attach(node);
                }
            }
        }

        T get(K key){
            LRUCachenode<K,T>* node = maper[key];
            if(node){
                detach(node);
                attach(node);
                return node->value;
            }else{
                return -1;
            }
        }
    private:
        void detach(LRUCachenode<K,T>* node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        void attach(LRUCachenode<K,T>* node){
            node->next = head->next;
            node->next->prev = node;
            node->prev = head;
            head->next = node;
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