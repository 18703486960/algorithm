#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
    int val;
    ListNode* next;
}ListNode;
// 两个两个合并不实用
/*
ListNode* mergeKLists(vector<ListNode*> &lists){
    if(lists.size() == 0)return nullptr;
    ListNode* p = lists[0];

    for(int i = 1; i < lists.size(); i++){
        //p = mergeTwoList(p, lists[i]);
    }
    return p;
}*/

struct greaterListNode{
    bool operator() (ListNode* x, ListNode* y) { return x->val > y->val;}
};
ListNode* mergeKLists(vector<ListNode*> &lists){
    if(lists.size() == 0){
        return nullptr;
    }

    if(lists.size() == 1){
        return lists[0];
    }

    ListNode* pre_head = new ListNode(-1);
    ListNode* pre = pre_head;
    priority_queue<ListNode*, vector<ListNode*>, greaterListNode> pq;

    for(auto& lst : lists){
        if(lst != nullptr)
            pq.push(lst);
    }

    while(!pq.empty()){
        pre->next = pq.top();
        pre = pre->next;
        pq.pop();
        if(pre != nullptr && pre->next != nullptr){
            pq.push(pre->next);
        }
    }
    ListNode* head = pre_head->next;
    delete pre_head;
    return head;
}