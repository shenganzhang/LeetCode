#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int target = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            target = i;
            break;
        }
    }
    if (target == -1) {
        sort(nums.begin(), nums.end());
        return;
    }
    int target_1 = -1;
    for (int i = nums.size() - 1; i > target; i--) {
        if (nums[i] > nums[target]) {
            target_1 = i;
            break;
        }
    }
    swap(nums[target], nums[target_1]);
    reverse(nums.begin() + target + 1, nums.end());
}


int main() {
    vector<int> nums({1,3,2});
    nextPermutation(nums);
}