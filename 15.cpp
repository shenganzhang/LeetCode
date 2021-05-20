#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        if (nums.size() < 3) {
            return results;
        }
        sort(nums.begin(), nums.end());
        for (unsigned int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > 0) {
                break;
            }
            unsigned int left = i + 1;
            unsigned int right = nums.size() - 1;
            while (left < right) {
                if ((nums[i] + nums[left] + nums[right]) == 0) {
                    results.push_back(vector<int>({nums[i], nums[left], nums[right]}));
                    while (left < right && nums[left + 1] == nums[left]) {
                        left++;
                    }
                    while (left < right && nums[right - 1] == nums[right]) {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if ((nums[i] + nums[left] + nums[right]) < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return results;
    }
};
