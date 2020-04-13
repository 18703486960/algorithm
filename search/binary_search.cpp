#include <iostream>

using namespace std;
/*
二分查找是一种非常高效的查找算法，高效到什么程度呢？我们来分析一下它的时间复杂度。

我们假设数据大小是 n，每次查找后数据都会缩小为原来的一半，也就是会除以 2。最坏情况下，直到查找区间被缩小为空，才停止。

被查找区间的大小变化：n、n/2、n/4、n/8 ... n/2^k

可以发现，每次比较后查找区间会呈等比数列缩小，且每一次缩小操作只涉及两个数据的大小比较，所以，经过了 k 次区间缩小操作，时间复杂度就是 O(k)，最终区间大小为n/2^k=1，我们可以求得 k=log2n，所以时间复杂度就是 O(logn)。

这种对数时间复杂度。这是一种极其高效的时间复杂度，有的时候甚至比时间复杂度是常量级 O(1) 的算法还要高效。为什么这么说呢？

因为 logn 是一个非常“恐怖”的数量级，即便 n 非常非常大，对应的 logn 也很小。比如 n 等于 2 的 32 次方，这个数很大了吧？大约是 42 亿。也就是说，如果我们在 42 亿个数据中用二分查找一个数据，最多需要比较 32 次。

我们用大 O 标记法表示时间复杂度的时候，一般会省略掉常数、系数和低阶。对于常量级时间复杂度的算法来说，O(1) 有可能表示的是一个非常大的常量值，比如 O(1000)、O(10000)。所以，常量级时间复杂度的算法有时候可能还没有 O(logn) 的算法执行效率高。
*/
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

 operator new和inplacement new的区别
12. 智能指针
13. 什么是循环引用，weak_ptr为什么可以解决循环引用