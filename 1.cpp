#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i <= nums.size(); i++) {
        if (map.find(nums[i]) == map.end()) {
            map[target - nums[i]] = i;
        } else {
            return vector<int>({i, map[nums[i]]});
        }
    }
    return vector<int>({0});
}

int main() {
    vector<int> x({3,2,4});
    twoSum(x, 6);
}
