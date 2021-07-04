ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    auto ptrA = headA;
    auto ptrB = headB;
    while (ptrA != ptrB) {
        if (ptrA) ptrA = ptrA->next;
        else ptrA = headB;
        if (ptrB) ptrB = ptrB->next;
        else ptrB = headA;
    }
    return ptrA;
//    unordered_set<ListNode*> elementOfA;
//    while (headA) {
//        elementOfA.insert(headA);
//        headA = headA->next;
//    }
//    while (headB) {
//        if (elementOfA.count(headB)) return headB;
//        headB = headB->next;
//    }
//    return nullptr;
}