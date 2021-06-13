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

void backtrack(vector<int> &subset, vector<vector<int>> &subsets, vector<int>& nums, int index) {

    if (index == nums.size()) {
        subsets.push_back(subset);
        return;
    }

    backtrack(subset, subsets, nums, index + 1);
    subset.push_back(nums[index]);
    backtrack(subset, subsets, nums, index + 1);
    subset.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<int> subset;
    vector<vector<int>> subsets;
    int index = 0;
    backtrack(subset, subsets, nums, index);
    return subsets;
}