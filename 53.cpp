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

int maxSubArray(vector<int> &nums) {
    int result = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        result = max(result, sum);
        if (sum < 0) sum = 0;
    }
    return result;
//    dp
//    vector<int> dp(nums.size(), 0);
//    int result = INT_MIN;
//    for (int i = 0; i < nums.size(); ++i) {
//        if (i==0) dp[i] = nums[0];
//        else dp[i] = max(dp[i-1] + nums[i], nums[i]);
//        result = max(result, dp[i]);
//    }
//    return result;
}

int main() {
    vector<int> x({-2, 1, -3, 4, -1, 2, 1, -5, 4});
    maxSubArray(x);
}