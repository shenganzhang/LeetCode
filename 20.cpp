#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;


bool isValid(string s) {
    stack<char> container;
    unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
    };
    for (char &i : s) {
        if (i == '(' || i == '[' || i == '{') {
            container.push(i);
        }
        if (i == ')' || i == ']' || i == '}') {
            if (container.empty()) return false;
            auto last = container.top();
            container.pop();
            if (last != map[i]) return false;
        }
    }
    if (container.empty()) return true;
    else return false;
}



int main() {
    string s = "{[]}";
    cout << isValid(s);
}