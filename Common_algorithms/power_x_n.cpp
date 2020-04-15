#include <iostream>

using namespace std;

bool checkPowerOf2(int n){
    if(n < 1){
        return false;
    }else{
        return 0 == (n & (n - 1));
    }
}

int main(){

    return 0;
}