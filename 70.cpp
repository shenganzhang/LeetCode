#include <iostream>
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

int climbStairs(int n) {
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        if (i == 0 || i == 1) dp[i] = i + 1;
        else dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}