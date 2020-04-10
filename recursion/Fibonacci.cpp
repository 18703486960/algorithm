#include <iostream>

// 递归
int Fibonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// 非递归
int Fibonacci_(int n){
    int result[] = {0,1};
    if(n < 2){
        return result[n];
    }
    long Fibone = 1;
    long Fibtwo = 0;
    long Fibn = 0;
    for(int i = 2; i <= n; i++){
        Fibn = Fibone + Fibtwo;
        Fibtwo = Fibone;
        Fibone = Fibn;
    }
    return Fibn;
}

int main(){
    int ret = Fibonacci_(40);
    std::cout << ret << '\n';
    return 0;
}