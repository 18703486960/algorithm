#include <iostream> 
#include <algorithm> 
#include <iterator>
#include <vector> 

void merge_sort(std::vector<int>& arr, std::vector<int>::iterator left, 
                std::vector<int>::iterator right, std::vector<int>::iterator out){
  if(left != right){
    auto mid = left + ((right - left) >> 1);
    merge_sort(arr, left, mid, out);
    merge_sort(arr, mid, right, out);
    std::merge(left, mid, mid, right, out);
  }
}

int main(int argc, char const* argv[])
{
  std::vector<int> arr{1223, 4, 23, 3, 76, 787, 455 , 6, 4, 2, 45, 56};
  std::vector<int> result;
  merge_sort(arr, std::begin(arr), std::end(arr), std::begin(result));
  for(auto item : arr){
    std::cout << item << '\n';
  }
  return 0;
}
