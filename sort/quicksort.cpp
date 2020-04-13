#include <iostream>
#include <stack>
using namespace std;

int selectPivotmeofthree(int* arr, int left, int right){
    int mid = left + ((right - left) >> 1);

    if(arr[mid] > arr[right]){
        swap(arr[mid], arr[right]);
    }
    if(arr[left] > arr[right]){
        swap(arr[right], arr[left]);
    }
    if(arr[mid] < arr[left]){
        swap(arr[mid], arr[left]);
    }
    return arr[left];
}

int partition(int* arr, int left, int right){
    int temp = arr[left];
    while(left < right){
        while(arr[right] >= temp && left < right){
            right--;
        }
        arr[right] = arr[left];
        while(arr[left] <= temp && left < right){
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = temp;
    return left;
}
// 递归
void quick_sort(int* arr, int left, int right){
    if(left < right){
        int pivod = partition(arr, left, right); 
        quick_sort(arr, left, pivod - 1);
        quick_sort(arr, pivod + 1, right);
    }
}
// 非递归
void quick_sort_(int* arr, int left, int right){
    stack<int> s;
    s.push(left);
    s.push(right);
    while(!s.empty()){
        int right = s.top();
        s.pop();
        int left = s.top();
        s.pop();

        int pivod = partition(arr, left, right);
        if(pivod > left+1){
            s.push(left);
            s.push(pivod-1);
        }
        if(pivod < right - 1){
            s.push(pivod+1);
            s.push(right);
        }
    }
}
int main(){
    int arr[] = {12, 32, 11, 43, 22, 145, 223};
    int len = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, len-1);
    for(auto i : arr){
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}