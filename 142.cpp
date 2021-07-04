ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
        if (!fast) return nullptr;
        fast = fast->next;
        if (fast == slow) {
            ListNode* third = head;
            while (third != slow) {
                third = third->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return nullptr;
}