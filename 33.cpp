#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int search(vector<int> &nums, int target) {

    // leetcode official solution
    int begin = 0;
    int end = nums.size() - 1;

    if (!n) {
        return -1;
    }
    if (n == 1) {
        return nums[0] == target ? 0 : -1;
    }

    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (nums[mid] == target) return mid;
        if (nums[0] <= nums[mid]) {
            if (target >= nums[0] && target < nums[mid]) {
                end = mid - 1;
            }
            else {
                begin = mid + 1;
            }
        }
        else {
            if (target > nums[mid] && target <= nums[nums.size() - 1]) {
                begin = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }

    return -1;

//    while (begin != end) {
//        int mid = (begin + end) / 2;
//        if (nums[mid] == target) return mid;
//        else {
//            if (nums[mid] < target) {
//                if (nums[mid] < mid) end = mid;
//                else begin = mid + 1;
//            } else {
//                if (nums[mid] > mid) begin = mid + 1;
//                else end = mid;
//            }
//        }
//    }
//    if (nums[begin] == target) return begin;
//    return -1;
}


int main() {
    vector<int> nums({1,3,5});
    cout << search(nums, 1);
}