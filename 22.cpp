#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

void backtrack(vector<string> &combs, int leftCount, int rightCount,
               string& comb, stack<char> & check, const int n) {
    if (leftCount == n && rightCount == n) {
        combs.push_back(comb);
        return;
    }
    if (leftCount < n) {
        comb += '(';
        check.push('(');
        backtrack(combs, leftCount + 1, rightCount, comb, check, n);
        comb.pop_back();
        check.pop();
    }
    if (rightCount < n) {
        if (!check.empty() && check.top() == '(') {
            comb += ')';
            check.pop();
            backtrack(combs, leftCount, rightCount + 1, comb, check, n);
            comb.pop_back();
            check.push('(');
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> combs;
    int leftCount = 0;
    int rightCount = 0;
    string comb;
    stack<char> check;
    backtrack(combs, leftCount, rightCount, comb, check, n);
    return combs;
}


int main() {
    generateParenthesis(3);
}