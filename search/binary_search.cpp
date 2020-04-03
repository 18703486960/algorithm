#include <iostream>

using namespace std;

// 递归实现
int binary_search(int* arr, int left, int right, int value){
    if(left > right){
        return -1;
    }else{
        int mid = left + (right - left)/2;
        if(value == arr[mid]){ return mid; }
        if(value < arr[mid]){
            binary_search(arr, left, mid-1, value);
        }else{
            binary_search(arr, mid + 1, right, value);
        }
    }
}
void binary_test_one(){
    int arr[] =   {12, 14, 22, 66, 67, 88};
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = binary_search(arr, 0, len - 1, 67);
    cout << ret << endl;
}



// 非递归实现
int binary_search_(int *arr, int left, int right, int value){
    if(left > right){
        return -1;
    }
    while(left < right){
        int mid = left + ((right - left) >> 1);
        if(arr[mid] == value){
            return mid;
        }
        if(arr[mid] < value){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}
void binary_test_two(){
    int arr[] =   {12, 14, 22, 66, 67, 88};
    int len = sizeof(arr)/sizeof(arr[0]);

    int ret = binary_search_(arr, 0, len - 1, 67);
    cout << ret << endl;
}
int main(){
    binary_test_one();
    binary_test_two();
    return 0;
}