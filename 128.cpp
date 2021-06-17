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

using namespace std;


int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;
    int currLength = 1;
    int maxLength = 1;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == nums[i - 1] + 1) currLength += 1;
        else if (nums[i] == nums[i - 1]) continue;
        else {
            if (currLength > maxLength) maxLength = currLength;
            currLength = 1;
        }
    }
    if (currLength > maxLength) maxLength = currLength;
    return maxLength;
}

//int longestConsecutive(vector<int>& nums) {
//    unordered_set<int> set;
//    for (const int& num : nums) {
//        set.insert(num);
//    }
//
//    int maxLength = 0;
//    for (const int& num : nums) {
//        if (!set.count(num - 1)) {
//            int currentNum = num;
//            int currentLength = 1;
//            while (set.count(currentNum + 1)) {
//                currentNum += 1;
//                currentLength += 1;
//            }
//            maxLength = max(currentLength, maxLength);
//        }
//    }
//    return maxLength;
//}

int main() {
    vector<int> nums({1,2,0,1});
    longestConsecutive(nums);
}