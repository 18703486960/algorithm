#include <iostream>

using namespace std;

int partition(int* arr, int left, int right){
    int temp = arr[left];
    while(left < right){
        while(arr[right] >= temp && left < right){
            right--;
        }
        arr[left] = arr[right];
        while(arr[left] <= temp && left < right){
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = temp;
    return left;
}

int quick_select(int* arr, int left, int right, int k){
    if(left >= right){
        return arr[left];
    }
    while(left < right){
        int index = partition(arr, left, right);
        if(index < k - 1){
            left = index + 1;
        }else if(index == k - 1){
            return arr[index];
        }else{
            right = index - 1;
        }
    }
}

int main(){
    int arr[] = {12, 42, 55, 22, 67};
    int len = sizeof(arr)/sizeof(arr[0]);
    int ret = quick_select(arr, 0, len - 1, 3);
    cout << ret << endl;
    return 0;
}