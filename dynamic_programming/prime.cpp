#include <iostream>
#include <list>

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