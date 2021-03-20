#include <iostream> 
#include <algorithm> 
#include <memory>
#include <vector>

void bubble_sort(std::vector<int>& bubble){
  for(int i = 0; i < bubble.size(); ++i){
    bool flag = false;
    for(int j = i + 1; j < bubble.size(); ++j){
      if(bubble.at(j - 1) > bubble.at(j)){
        flag = true;
        std::swap(bubble[j - 1], bubble[j]);
      }
    }
    if(!flag){
      break;
    }
  }
}

int main(int argc, char const* argv[])
{
  std::vector<int> arr = {12, 2, 454, 34, 232, 23, 656, 3432, 545};  
  bubble_sort(arr);
  for(int item : arr){
    std::cout << item << " ";
  }
  std::cout << '\n'; 
  return 0;
}
