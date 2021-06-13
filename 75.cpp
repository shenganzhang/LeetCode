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

void sortColors(vector<int>& nums) {
    int ptr = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == 0) {
            swap(nums[ptr], nums[i]);
            ptr++;
        }
    }
    for (int i = ptr; i < nums.size(); ++i) {
        if (nums[i] == 1) {
            swap(nums[ptr], nums[i]);
            ptr++;
        }
    }
}