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

bool canJump(vector<int>& nums) {
    int limits = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i <= limits) {
            limits = max(i + nums[i], limits);
        }
        if (limits >= nums.size() - 1) return true;
    }
    return false;
}