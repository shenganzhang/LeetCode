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
#include <climits>
#include <queue>

using namespace std;

int numIslands(vector<vector<char>>& grid) {
    int num = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '0' || visited[i][j]) continue;
            stack<pair<int, int>> investigate;
            investigate.push(make_pair(i, j));
            while (!investigate.empty()) {
                auto next = investigate.top();
                investigate.pop();
                int row = next.first;
                int col = next.second;
                visited[row][col] = true;
                vector<pair<int, int>> possibles({
                                                         make_pair(row - 1, col), make_pair(row + 1, col), make_pair(row, col - 1), make_pair(row, col + 1)
                                                 });
                for (auto & possible : possibles) {
                    auto _row = possible.first;
                    auto _col = possible.second;
                    if (0 <= _row && _row < n && 0 <= _col && _col < m && !visited[_row][_col] && grid[_row][_col] == '1')
                        investigate.push(make_pair(_row, _col));
                }
            }
            num++;
        }
    }
    return num;
}

int main() {
    vector<vector<char>> grid;
    grid.push_back(vector<char>({'1', '1', '0', '1', '1'}));
    grid.push_back(vector<char>({'1', '1', '0', '1', '1'}));
    numIslands(grid);
}