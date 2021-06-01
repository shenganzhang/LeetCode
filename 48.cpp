#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int len = matrix.size();
    for (int count = 0; count < len / 2; ++count) {
        for (int j = count; j < len - count - 1; ++j) {
            int temp = matrix[count][j];
            matrix[count][j] = matrix[len - 1 - j][count];
            matrix[len - 1 - j][count] = matrix[len - 1 - count][len - 1 - j];
            matrix[len - 1 - count][len - 1 - j] = matrix[j][len - 1 - count];
            matrix[j][len - 1 - count] = temp;
        }
    }
    }
}

int main() {
    vector<vector<int>> nums;
    nums.push_back(vector<int>({1, 2, 3}));
    nums.push_back(vector<int>({4, 5, 6}));
    nums.push_back(vector<int>({7, 8, 9}));
    rotate(nums);
}