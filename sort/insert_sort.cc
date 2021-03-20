#include <vector> 
#include <iostream> 

// stable sort && support list
void insert_sort(std::vector<int>& arr){
  for(int i = 1; i < arr.size(); ++i){
    int item = arr.at(i);
    int j;
    for(j = i - 1; j >= 0 && arr.at(j) > item; --j){
        arr[j + 1] = arr[j]; 
    }
    arr[j + 1] = item;
  }
}

// stable sort && not support list
void binary_insert_sort(std::vector<int>& arr){
  for(int i = 1; i < arr.size(); ++i){
    int left = 0, right = i, item = arr.at(i);
    while(left < right){
      int mid = left + ((right - left) >> 1);
      if(arr[mid] < item){
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    for(int j = i; j > left; --j){
      arr[j] = arr[j - 1];
    }
    arr[left] = item;
  }
}

// void shell_sort_helper(std::vector<int>& arr, int num){
//   for(int i = 0; i + num < arr.size(); ++i){
//     for(int j = i + num; j < arr.size(); j += num){
//       int item = arr.at(j);
//       int k;
//       for(k = j - num; k >= i && arr[k] > item; k -= num){
//         arr[k + num] = arr[k];
//       }
//       arr[k + num] = item; 
//     }
//   }
// }

// not stable and not support list
void shell_sort_helper(std::vector<int>& arr, int num){
  for(int i = num; i < arr.size(); ++i){
    int item = arr.at(i);
    int j;
    for(j = i - num; j >= 0 && arr.at(j) > item; j -= num){
      arr[j + num] = arr[j];
    }
    arr[j + num] = item;
  }
}

// not stable sort && not support list
void shell_sort(std::vector<int>& arr, const std::vector<int>& nums){
  for(int num : nums){
    shell_sort_helper(arr, num);
  }
}
int main(int argc, char const* argv[])
{
  std::vector<int> arr{12, 3, 45, 66, 33, 21, 34, 12, 23, 5464, 33, 2323, 253, 34};
  // insert_sort(arr);
  // binary_insert_sort(arr);
  shell_sort(arr, std::vector<int>{1});
  for(int item : arr){
    std::cout << item << " ";
  }
  std::cout << '\n';
  return 0;
}
