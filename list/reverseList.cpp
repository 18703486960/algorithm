#include <iostream>

using namespace std;

typedef struct{
    int val;
    ListNode* next;
}ListNode;

// 非递归
ListNode* reverseList(ListNode* head){
    if(head == nullptr){
        return nullptr;
    }
    ListNode* prev = nullptr;
    while(head != nullptr){
        ListNode* curr = head;
        head = head->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}

// 递归
ListNode* reverseList(ListNode* head){
    if(head == nullptr){
        return head;
    }
    if(head->next == nullptr){
        return head;
    } 
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}