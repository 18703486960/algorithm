struct ListNode{
	int val;
	LinkNode* next;
};

bool is_have_loop(ListNode* root){
	if(root == nullptr){
		return -1;
	}
	ListNode* runner = root;
	ListNode* chaser = root;

	while(runner->next && runner->next->next){
		if(runner = chaser){
			return true;
		}
		runner = runner->next->next;
		chaser = chaser->next;
	}
	return false;
}