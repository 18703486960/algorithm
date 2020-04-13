#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
Sum Find a pair of two elements in an array, whose sum is a given target number.Assume only one qualified pair of numbers existed in the array, return the index of there numbers*/

int partition(int* arr, int left, int right){
	int temp = arr[left];
	while(left < right){
		while(arr[right] >= temp && left < right){
			right--;
		}
		arr[left] = arr[right];
		while(arr[left] <= temp && left < right){
			left++;
		} 
		arr[right] = arr[left];
	}
	arr[left] = temp;
	return left;
}
void quickSort(int* arr, int left, int right){
	if(left < right){
		int pivod = partition(arr, left, right);
		quickSort(arr, left, pivod - 1);
		quickSort(arr, pivod + 1, right); 
	}
}

// map, O(n)
vector<int> addsToTarget(vector<int> &numbers, int target){
	unordered_map<int, int> numToIndex;
	vector<int> vi(2);
	for(auto it = numbers.begin(); it != numbers.end(); it++){
		if( numToIndex.count(target - *it)){
			vi[0] = numToIndex[target - *it] + 1;
			vi[1] = (int)(it - numbers.begin()) + 1;
			return vi;
		}
		numToIndex[*it] = (int)(it - numbers.begin());
	}
} 

// quicksort, O(nlgn)
bool hashArrayTwoCandidates(int* arr, int size, int sum){
	quickSort(arr, 0, size - 1);
	int l = 0, r = size - 1;
	while(l < r){
		int sum_ = arr[l] + arr[r];
		if(sum_ == sum){
			return true;
		}else if(sum_ < sum){
			l++;
		}else{
			r--;
		}
	}
	return false;
}

int main(){

	return 0;
}
