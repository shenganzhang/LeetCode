#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

void backtrack(const vector<int> &candidates, int target,
               int sum, vector<int> &result, vector<vector<int>> &results, int index) {
    if (index == candidates.size()) return;
    if (sum == target) {
        results.push_back(result);
        return;
    } else {
        backtrack(candidates, target, sum, result, results, index + 1);
        if (sum + candidates[index] <= target) {
            result.push_back(candidates[index]);
            backtrack(candidates, target, sum + candidates[index], result, results, index);
            result.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    int sum = 0;
    vector<int> result;
    vector<vector<int>> results;
    int index = 0;
    backtrack(candidates, target, sum, result, results, index);
    return results;
}


int main() {
    vector<int> nums({2, 3, 6, 7});
    combinationSum(nums, 7);
}