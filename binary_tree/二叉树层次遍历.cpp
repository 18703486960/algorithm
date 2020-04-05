#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct ListNode{
    int val;
    ListNode* left;
    ListNode* right;
};
vector<int> LevelOrderTraversal(ListNode* root){
    vector<int> result;
    if(root == nullptr){
        return result;
    }
    queue<ListNode*> q;
    q.push(root);
    while(!q.empty()){
        ListNode* curr = q.front();
        q.pop();
        result.push_back(curr->val);
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
    }
}