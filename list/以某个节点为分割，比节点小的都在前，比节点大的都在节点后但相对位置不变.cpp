#include <iostream>

struct ListNode{
	int val;
	ListNode* next;
	ListNode (int value)
		:	val(value){
			next = nullptr;
		}
};

ListNode* partition(ListNode* root, int value){
	if(root == nullptr){
		return nullptr;
	}
	ListNode* dummyleft = new dummyleft(0);
	ListNode* dummyright = new dummyright(0);

	ListNode* left = dummyleft;
	ListNode* right = dummyright;

	ListNode* curr = root;
	while(curr && curr->next != nullptr){
		if(curr->val < value){
			left -> next = new ListNode(value);
		}else{
			right -> next = new ListNode(value);
		}
	}
	left->next = dummyright->next;
	right->next = nullptr;
	return dummyleft->next;
}