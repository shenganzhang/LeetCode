#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target) {
    if (nums.size() == 1) {
        if (nums[0] == target) return vector<int>({0, 0});
    }
    int begin = 0;
    int end = nums.size() - 1;
    int rangeStart = -1;
    int rangeEnd = -1;
    while (begin < end) {
        int mid = (begin + end) >> 1;
        if (nums[mid] == target) {
            if (mid != 0 && nums[mid - 1] == target) {
                end = mid;
            } else {
                rangeStart = mid;
                break;
            }
        } else if (nums[mid] < target) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    if (begin == end) {
        if (nums[begin] == target) rangeStart = begin;
    }
    begin = 0;
    end = nums.size() - 1;
    while (begin < end) {
        int mid = (begin + end) >> 1;
        if (nums[mid] == target) {
            if (mid != (nums.size() - 1) && nums[mid + 1] == target) {
                begin = mid + 1;
            } else {
                rangeEnd = mid;
                break;
            }
        } else if (nums[mid] < target) {
            begin = mid + 1;
        } else {
            end = mid;
        }
    }
    if (begin == end) {
        if (nums[begin] == target) rangeEnd = begin;
    }
    return vector<int>({rangeStart, rangeEnd});
}


int main() {
    vector<int> nums({2, 2});
    searchRange(nums, 2);
}