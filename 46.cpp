#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

void backtrack(vector<int> &nums, int index,
               vector<vector<int>> &combinations) {
    if (index == nums.size()) {
        combinations.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        backtrack(nums, index + 1, combinations);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> combinations;
    int index = 0;
    backtrack(nums, index,combinations);
    return combinations;
}


int main() {
    vector<int> nums({2, 3, 6, 7});
}