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

int uniquePaths(int m, int n) {
    vector<vector<int>> map(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) {
                map[i][j] = 1;
                continue;
            }
            if (i == 0) {
                map[i][j] = map[i][j - 1];
                continue;
            }
            if (j == 0) {
                map[i][j] = map[i - 1][j];
                continue;
            }
            map[i][j] = map[i - 1][j] + map[i][j - 1];
        }
    }
    return map[m - 1][n - 1];
}