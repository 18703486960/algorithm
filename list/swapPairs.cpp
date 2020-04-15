ListNode* swapPairs(ListNode* head){
    if(head == nullptr){
        return head;
    }

    ListNode* dummy = new ListNode(0);
    ListNode* prev = dummy;
    ListNode* node1 = head;
    ListNode* node2 = head->next;
    while(node1 && node1->next){
        node2 = node1->next;

        prev->next = node1->next;

        node1->next = node2->next;
        node2->next = node1;

        prev = node1;
        node1 = prev->next;
    }

    return dummy->next;
}