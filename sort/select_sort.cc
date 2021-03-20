#include <iostream> 
#include <type_traits>
#include <vector> 

using namespace std;

void select_sort(vector<int>& arr){
  for(int i = 0; i < arr.size(); ++i){
    int min = INT_MAX, min_index = 0;
    for(int j = i;j < arr.size(); ++j){
      if(arr.at(j) < min){
        min = arr.at(j);
        min_index = j;
      }
    }
    if(i != min_index){
      swap(arr[i], arr[min_index]);
    }
  }
}
int main(int argc, char const* argv[])
{
  vector<int> arr{12, 242, 3, 545, 23, 56, 23};
  select_sort(arr);
  for(int item : arr){
    cout << item << " ";
  }
  cout << '\n';
  return 0;
}
