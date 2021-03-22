#include <algorithm> 
#include <iterator>
#include <utility>
#include <vector> 
#include <iostream> 

void heap_iterator_sort(std::vector<int>& arr){
  std::make_heap(std::begin(arr), std::end(arr));
  for(int i = arr.size() - 1; i > 0; --i){
    std::swap(arr[i], arr[0]);
    std::make_heap(std::begin(arr), std::begin(arr) + i);
  }
}

int main(int argc, char const* argv[])
{
  std::vector<int> arr{213, 23, 334, 23, 445, 34, 67, 234, 67, 134, 66, 55, 4}; 
  for(auto item : arr){
    std::cout << item << " ";
  }
  std::cout << '\n';
  heap_iterator_sort(arr);
  for(auto item : arr){
    std::cout << item << " ";
  }
  std::cout << '\n';

  return 0;
}
