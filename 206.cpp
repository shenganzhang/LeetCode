#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
#include <algorithm>
#include <stack>
#include <utility>
#include <set>
#include <limits>
#include <climits>
#include <queue>

using namespace std;

int numIslands(vector<vector<char>>& grid) {
    ListNode* reverseList(ListNode* head) {
        stack<int> temp;
        while (head) {
            temp.push(head->val);
            head = head->next;
        }
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;
        while (!temp.empty()) {
            ptr->next = new ListNode(temp.top());
            temp.pop();
            ptr = ptr->next;
        }
        return result->next;
    }
}