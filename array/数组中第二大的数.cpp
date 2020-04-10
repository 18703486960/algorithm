#include <iostream>
using namespace std;

int two_rank(int* arr, int len){
    int min = 0;
    int two_min = 0;
    if(len < 2)return -1;
    for(int i = 0; i < len; i++){
        if(i == 0){
            min = arr[0];
        }else if(i == 1){
            if(arr[1] < min){
                two_min = min;
                min = arr[1];
            }else{
                two_min = arr[1];
            }
        }else{
            if(arr[i] < min){
                two_min = min;
                min = arr[i];
            }else if(arr[i] >= min && arr[i] < two_min){
                two_min = arr[i];
            }else{
                continue;
            }
        }   
    }
    return two_min;
}

int main(){
    int arr[] = {123, 241, 222, 12, 567, 222, 12234, 22};
    int len = sizeof(arr)/sizeof(arr[0]);
    int ret = two_rank(arr, len);
    cout << ret << '\n';
    return 0;
}