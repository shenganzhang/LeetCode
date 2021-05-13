#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

// tricks: rolling array
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    auto mergeResult = new ListNode();
    auto last = mergeResult;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            last->next = l1;
            l1 = l1->next;
        }
        else {
            last->next = l2;
            l2 = l2->next;
        }
        last = last->next;
    }
    if (l1) {
        last->next = l1;
    } else {
        last->next = l2;
    }
    return mergeResult->next;
}
