#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

struct MapValue{
  int value;
  list<int>::iterator node_list_iter;
};

class LRU{
  public:
   LRU(size_t capacity) : capacity(capacity){}
    int Get(int key){
      if(_map.count(key)){
        auto& value = _map[key];
        int val = *value.node_list_iter;
        list_.erase(value.node_list_iter);
        list_.emplace_back(val);
        value.node_list_iter = --list_.end();
        return val;
      }
      return -1;
    }
    void Set(int key, int val){
      if(_map.size() == capacity){
        _map.erase(list_.front());
        list_.pop_front();
        Set(key, val);
      } else {
        list_.emplace_back(key);
        _map[key] = MapValue{val, --list_.end()};
      }
    }
   private:
   const size_t capacity;
   unordered_map<int, MapValue> _map;
   list<int> list_;
};

int main(int argc, char const* argv[])
{
  LRU l(2);
  l.Set(1, 1);
  l.Set(2, 2);
  cout << l.Get(1);
  l.Set(3, 3);
  cout << l.Get(2);
  l.Set(4, 4);
  cout << l.Get(1);
  cout << l.Get(3);
  cout << l.Get(4);
  return 0;
}
