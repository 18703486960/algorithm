#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void heapify(vector<int>& arr, int opt, int end){
  int father = opt;
  int child = father * 2 + 1;
  while(child < end){
    if(child + 1 < end && arr.at(child) < arr.at(child + 1)){
      child += 1;
    }
    if(arr.at(child) < arr.at(father)){
      return;
    }
    swap(arr[father], arr[child]);
    father = child;
    child = father * 2 + 1;
  }
}

void heap_sort(vector<int>& arr){
  for(int i = (arr.size() >> 1) - 1; i >= 0; i--){
    heapify(arr, i, arr.size());   
  }
  for(int i = arr.size() - 1; i > 0; i--){
    swap(arr[0], arr[i]);
    heapify(arr, 0, i);
  }
}

int main(int argc, char const* argv[]) {
  vector<int> arr{123, 3, 1231, 46, 34, 56547, 67, 5, 34, 3, 423};
  for(int item : arr){
    cout << item << " ";
  }
  cout << '\n';
  heap_sort(arr);
  for(int item : arr){
    cout << item << " ";
  }
  cout << '\n';
  return 0;
}
