#include <iostream>
#include <bitset>

using namespace std;

int main(){
    bitset<40> imFiveByteLong;
    bool isItSet = imFiveByteLong.test(0);
    size_t numSet = imFiveByteLong.count();
    cout << isItSet << " " << numSet << endl;
    return 0;
}