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

int rob(vector<int> &nums) {
    vector<int> dp(nums.size());
    for (int i = 0; i < dp.size(); ++i) {
        if (i == 0) dp[i] = nums[i];
        else if (i == 1) dp[i] = max(nums[0], nums[1]);
        else {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
    }
    return dp[dp.size() - 1];
}

int main() {
    vector<int> x({1, 2, 3, 1});
    int y = rob(x);
    cout << y;
}