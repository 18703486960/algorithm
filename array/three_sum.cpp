#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

// use sort
set<vector<int>> find_three(vector<int> arr){
    sort(arr.begin(), arr.end());
    set<vector<int>>results;
    vector<int> result(3);
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int k = arr.size() - 1;
        int j = i + 1;
        while(j < k){
            int sum_two = arr[i] + arr[j];
            if(sum_two + arr[k] < 0){
                j++;
            }else if(sum_two + arr[k] > 0){
                k--;
            }else{
                result[0] = arr[i];
                result[1] = arr[j];
                result[2] = arr[k];
                results.insert(result);
                j++;
                k--;
            }
        }
    }
    return results;
}

// use hash
set<vector<int>> find_three_(vector<int> arr){
    unordered_map<int, int> hash;
    set<vector<int>> results;
    vector<int> result(3);
    for(int i = 0; i < arr.size(); i++){
        hash[arr[i]] = i; 
    }

    unordered_map<int, int>::iterator iter;
    for(int i = 0; i < arr.size() - 1; i++){
        for(int j = i + 1; j < arr.size(); j++){
            int sum = arr[i] + arr[j];
            iter = hash.find(0 - sum);
            if(iter != hash.end()){
                if(iter->second > j){
                    result[0] = arr[i];
                    result[1] = arr[j];
                    result[2] = (*iter).first;
                    sort(begin(result), end(result));
                    results.insert(result); 
                }
            }
        }
    }
    return results;
}

int main(){
    vector<int>arr {-1, 0, 1, 2, -1, -4};
    set<vector<int>> ret;
    ret = find_three_(arr);
    for(auto i = begin(ret); i != end(ret); i++){
        copy(begin(*i), end(*i), ostream_iterator<int>{cout, ", "});
        cout << "\n";
    }
    return 0;
}