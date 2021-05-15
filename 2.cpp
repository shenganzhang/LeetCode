#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// last digit
// add 0 to empty
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    bool addOne = false;
    auto sum = new ListNode();
    auto last = sum;
    while (l1 && l2) {
        int result;
        if (addOne) {
            result = 1 + l1->val + l2->val;
        }
        else {
            result = l1->val + l2->val;
        }
        last->next = new ListNode(result % 10);
        addOne = (bool) (result / 10);
        last = last->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (!l1 & !l2) {
        return sum->next;
    }
    ListNode *remain;
    if (l1) {
        remain = l1;
    } else {
        remain = l2;
    }
    while (remain) {
        int result;
        if (addOne) {
            result = remain->val + 1;
        }
        else {
            result = remain->val;
        }
        last->next = new ListNode(result % 10);
        addOne  = (bool) (result / 10);
        last = last->next;
        remain = remain->next;
    }
    if (addOne) {
        last->next = new ListNode(1);
    }
    return sum->next;
}