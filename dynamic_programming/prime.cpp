#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int Getnthprime(int n){
    list<int> primes (1, 2);
    int number = 3;
    while(primes.size() != n){
        bool isPrime = true;
        for(auto it = primes.begin();
            it != primes.end() && (*it)*(*it) <= number; it++)
        {
            if(number % (*it) == 0){
                isPrime = false;
            }
        }

        if(isPrime){
            primes.push_back(number);
        }
        number += 2;
    }
    return *(primes.rbegin());
}

int main(){
    int ret = Getnthprime(30);
    cout << ret << endl;
    return 0;
}


bool isPrime(int num){
    if(num <= 3){
        return num > 1;
    }
    if(num % 6 != 1 && num % 6 != 5)return false;
    int sqrt_ = static_cast<int>(sqrt(num)); 
    for(int i = 5;i <= sqrt_; i+=6){
        if(num % i == 0 || num % (i+2) == 0){
            return false;
        }
    }
    return true;
}