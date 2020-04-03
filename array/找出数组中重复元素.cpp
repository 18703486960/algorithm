#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 排序后遍历，暴力法 
vector<int> duplicate_one(int* arrs, int length){
	vector<int> result;
	if(length < 0 || arrs == nullptr){
		return result;
	}
	sort(arrs, arrs+length);
	for(int i = 1; i < length; i++){
		if(arrs[i] == arrs[i-1]){
			result.push_back(arrs[i]);
			i++;
		} 
	}
	return result;
}


// 哈希~ 
vector<int> duplicate_two(int* arrs, int length){
	vector<int> result;
	if(length < 0 || arrs == nullptr){
		return result;
	}
	int *temp = new int[length];
	
	for(int i = 0; i < length; i++){
		temp[i] = 0;
	}
	for(int i = 0; i < length; i++){
		temp[arrs[i]]++;
	}
	
	for(int i = 0; i < length; i++){
		if(temp[i]>1){
			result.push_back(i);
		}
	}
	delete[] temp;
	return result;
}


//vector<int> duplicate_three(int* arrs, int length){
//	vector<int> result;
//	if(arrs == nullptr || length < 0 || length == 1){
//		return result;
//	}
//	for(int i = 0; i < length; i++){
//		if(arrs[i] < 0 || arrs[i] > length - 1){
//			return result;
//		}
//	}
//	
//	for(int i = 0; i < length;i++){
//		int count = 0;
//		while(arrs[i] != i){
//			if(count > length)
//				break;
//			if(arrs[arrs[i]] == i) {
//				result.push_back(arrs[i]);
//				return result;      
//			}
//			int temp = arrs[arrs[i]];
//			arrs[arrs[i]] = arrs[i];
//			arrs[i] = temp;
//			count++; 			
//		}
//	}
//	return result;
//}

int main(){
	int arr[] = {2, 1, 2, 4, 1};
	vector<int> ret = duplicate_three(arr, sizeof(arr)/sizeof(arr[0]));
	
	for(int i = 0; i < ret.size(); i++){
		cout << ret.at(i) << " ";
	}
	cout << endl;
	
	return 0;
}
