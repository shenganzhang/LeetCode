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

using namespace std;


int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[i - j - 1] * dp[j];
        }
    }
    return dp[n];
}

int main() {
    cout << numTrees(3);
}