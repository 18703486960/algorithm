#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

struct ListNode;

struct CountListNode {
  int count;
  list<ListNode> node_list;
};

struct ListNode {
  int key;
  list<CountListNode>::iterator count_iter;
};

struct MapValue {
  int value;
  list<ListNode>::iterator list_node_iter;
};

class LFU {
 private:
  const size_t capacity;
  unordered_map<int, MapValue> _map;
  list<CountListNode> _count_list;

 public:
  LFU(size_t size) : capacity(size) {}
  void Put(int k, int v) {
    if (_map.size() == capacity) {
      auto begin_it = _count_list.begin();
      while (begin_it->node_list.empty()) {
        begin_it++;
      }
      _map.erase(begin_it->node_list.begin()->key);
      begin_it->node_list.pop_front();
      Put(k, v);
    } else {
      if (_count_list.empty()) {
        _count_list.emplace_back(CountListNode{1, list<ListNode>{}});
        Put(k, v);
      } else {
        _count_list.begin()->node_list.emplace_back(
            ListNode{k, _count_list.begin()});
        _map[k] = {v, --(_count_list.begin()->node_list.end())};
      }
    }
  }
  int Get(int k) {
    if (_map.count(k)) {
      auto& val = _map[k];
      int value = val.value;
      int cnt = val.list_node_iter->count_iter->count;
      if (cnt == _count_list.size()) {
        _count_list.emplace_back(CountListNode{cnt + 1, list<ListNode>{}});
        return Get(k);
      } else {
        (--_count_list.end())
            ->node_list.emplace_back(ListNode{k, (--_count_list.end())});
        val.list_node_iter->count_iter->node_list.erase(val.list_node_iter);
        val.list_node_iter = (--(--_count_list.end())->node_list.end());
      }
      return value;
    }
    return 0;
  }
};

int main(int argc, char const* argv[]) {
  {
    LFU lfu(2);
    lfu.Put(1, 1);
    lfu.Put(2, 2);
    assert(1 == lfu.Get(1));
    lfu.Put(3, 3);
    assert(!lfu.Get(2));
    assert(3 == lfu.Get(3));
    lfu.Put(4, 4);
    assert(!lfu.Get(1));
    assert(3 == lfu.Get(3));
    assert(4 == lfu.Get(4));
  }
  {
    LFU lfu(2);
    lfu.Put(3, 1);
    lfu.Put(2, 1);
    lfu.Put(2, 2);
    lfu.Put(4, 4);
    assert(2 == lfu.Get(2));
  }

  {
    LFU lfu(2);
    lfu.Put(2, 1);
    lfu.Put(3, 2);
    assert(2 == lfu.Get(3));
    assert(1 == lfu.Get(2));
    lfu.Put(4, 3);
    assert(1 == lfu.Get(2));
    assert(!lfu.Get(3));
    assert(3 == lfu.Get(4));
  }
  return 0;
}
