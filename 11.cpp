#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

// remove the smaller rod;
// width largest, but height cannot be larger
// remove a row/col in dp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxArea = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            maxArea = max(maxArea, area);
            if (height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return maxArea;
    }
};
