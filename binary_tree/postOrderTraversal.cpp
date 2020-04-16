#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> postOrderTraversal(TreeNode* root){
    vector<int> result;
    if(root == nullptr){
        return result;
    }
    stack<TreeNode*> s;
    stack<int> index;
    TreeNode* curr = root;
    while(!s.empty() || curr != nullptr){
        while(curr){
            s.push(curr);
            index.push(0);
            curr = curr->left;
        }
        if(index.top() == 1){
            result.push_back(s.top()->val);
            s.pop();
            index.pop();
        }else{
            curr = s.top();
            curr = curr->right;
            index.top() = 1;
        }
    }
}