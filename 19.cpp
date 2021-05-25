#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *last = head;
    ListNode *pointer_1 = head;
    ListNode *pointer_2 = head;
    for (int i = 0; i < n; i++) {
        pointer_2 = pointer_2->next;
    }
    while (pointer_2) {
        last = pointer_1;
        pointer_1 = pointer_1->next;
        pointer_2 = pointer_2->next;
    }
    // delete head
    if (pointer_1 == head) {
        return pointer_1->next;
    }
    else {
        last->next = pointer_1->next;
        return head;
    }
}


int main() {

}