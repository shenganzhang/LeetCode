bool hasCycle(ListNode *head) {
    if (!head) return false;
    if (!head->next) return false;
    ListNode* first = head;
    ListNode* second = head->next;
    while(first != second) {
        if (first) first = first->next;
        if (second) second = second->next;
        if (second) second = second->next;
    }
    if (first) return true;
    else return false;
}