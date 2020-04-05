// 给定一个数组，使数组的奇数在前半段，偶数在后半段，在原数组上操作
#include <iostream>
using namespace std;


void partition(int* arr, int left, int right){
    int temp;
    while(left < right){
        while((arr[right] % 2 == 1) && left < right){
            right--;
        }
        while((arr[left] % 2 == 0) && left < right){
            left++;
        }
        temp = arr[right];
        arr[right] = arr[left];
        arr[left] = temp; 
    }    
}

int main(){
    int arr[] = {12, 121, 23, 44, 221, 353, 222, 11,2222};
    int len = sizeof(arr) / sizeof(arr[0]);
    partition(arr, 0, len-1);

    for(auto i : arr){
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}