// Palindrome Partition
/*
Given a string s, we can partition s such that every segment is a palindrome（'abba' is a palindrome, 'a' is a palindrome, 'ab' is not）.
Please write a function to return the minimum cuts needed for a palindrome partitioning, giving string s*/

#include <iostream>
#include <iostream>
#include <vector>

using namespace std;


int minCut(string s){
    if(s.empty()) return 0;
    vector<vector<bool>> palin
        (s.size(), vector<bool>(s.size(),false));
    vector<int> minCut(s.size()+1, 0);
    for(int i = 0; i <= s.size(); i++){
        minCut[i] = s.size() - i - 1;
    }
}