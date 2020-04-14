#include <iostream>
using namespace std;

void merge_sort( int* arr, int* helper, int left, int right){
    if(left >= right){
        return;
    }

    int mid = left + ((right - left) >> 1);
    merge_sort( arr, helper, left, mid);
    merge_sort( arr, helper, mid + 1, right);

    // merge
    int helperLeft = left;
    int helperRight = mid + 1;
    int curr = left;
    for(int i = left; i <= right; i++){
        helper[i] = arr[i];
    }

    while(helperLeft <= mid && helperRight <= right){
        if(helper[helperLeft] < helper[helperRight]){
            arr[curr++] = helper[helperLeft++];
        }else{
            arr[curr++] = helper[helperRight++];
        }
    }

    while(helperLeft <= mid){
        arr[curr++] = arr[helperLeft++];
    }
}


int main(){
    int arr[] = {12, 45, 23, 15, 89, 56};
    int len = sizeof(arr)/sizeof(arr[0]);
    int* helper = new int[len];
    merge_sort(arr, helper, 0, len-1);
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    delete[] helper;
    return 0;
}