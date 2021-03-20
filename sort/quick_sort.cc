#include <iostream> 
#include <algorithm> 
#include <vector>

int partition(std::vector<int>& arr, int left, int right){
  int temp = arr.at(left);
  while(left < right){
    while(--right > left && arr[right] >= temp);
    arr[left] = arr[right];
    while(left < right && arr[left] <= temp){
      left++;
    }
    arr[right] = arr[left];
  }
  arr[left] = temp;
  return left;
}

void quick_sort(std::vector<int>& arr, int left, int right){
  if(left < right){
    int pivot = partition(arr, left, right);
    quick_sort(arr, left, pivot);
    quick_sort(arr, pivot + 1, right);
  }
} 

int main(int argc, char const* argv[])
{
  std::vector<int> arr{213, 23, 22, 211, 245, 455, 6, 8, 5, 12, 23, 3434, 23, 2, 23124, 343, 123};
  quick_sort(arr, 0, arr.size());
  for(int item : arr){
    std::cout << item << " ";
  }
  std::cout << '\n';
  return 0;
}
