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

class MinStack {
private:
    stack<int> container;
    int min = INT_MAX;
    int cnt = 0;

public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        if (val < min) {
            min = val;
            cnt = 1;
        }
        else if (val == min) {
            cnt++;
        }
        container.push(val);
    }

    void pop() {
        if (container.top() == min) {
            if (cnt > 1) {
                cnt--;
                container.pop();
            }
            else {
                container.pop();
                stack<int> temp;
                int next_min = INT_MAX;
                while (!container.empty()) {
                    if (container.top() < next_min) {
                        next_min = container.top();
                        cnt = 1;
                    }
                    else if (container.top() == next_min) {
                        cnt++;
                    }
                    temp.push(container.top());
                    container.pop();
                }
                while (!temp.empty()) {
                    container.push(temp.top());
                    temp.pop();
                }
                min = next_min;
                cnt = 1;
            }
        }
        else {
            container.pop();
        }
    }

    int top() {
        return container.top();
    }

    int getMin() {
        return min;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
}