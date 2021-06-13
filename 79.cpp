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

void backtrack(vector<int> &pos, int index, vector<vector<char>>& board, vector<vector<bool>> &visited,
               string word, bool &found) {
    if (found) return;
    if (index == word.length()) {
        cout << pos[0];
        cout << pos[1];
        found = true;
        return;
    }
    int i = pos[0];
    int j = pos[1];
    int m = board.size();
    int n = board[0].size();

    if (board[i][j] != word[index]) return;
    else if (index == word.length() - 1) {
        found = true;
        return;
    }
    visited[i][j] = true;

    if ((0 <= i - 1 && i - 1 < m && 0 <= j && j < n)) {
        if (!visited[i - 1][j]) {
            vector<int> next_pos({i - 1, j});
            backtrack(next_pos, index + 1, board, visited, word, found);
        }
    }
    if ((0 <= i + 1 && i + 1 < m && 0 <= j && j < n)) {
        if (!visited[i + 1][j]) {
            vector<int> next_pos({i + 1, j});
            backtrack(next_pos, index + 1, board, visited, word, found);
        }
    }
    if ((0 <= i && i < m && 0 <= j - 1 && j - 1 < n)) {
        if (!visited[i][j - 1]) {
            vector<int> next_pos({i, j - 1});
            backtrack(next_pos, index + 1, board, visited, word, found);
        }
    }
    if ((0 <= i && i < m && 0 <= j + 1 && j + 1 < n)) {
        if (!visited[i][j + 1]) {
            vector<int> next_pos({i, j + 1});
            backtrack(next_pos, index + 1, board, visited, word, found);
        }
    }
    visited[i][j] = false;
}

bool exist(vector<vector<char>>& board, string word) {
    int index = 0;
    bool found = false;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j){
            vector<int> pos({i, j});
            backtrack(pos, index, board, visited, word, found);
        }
    }
    return found;
}

int main() {
    vector<vector<char>> board;
    board.push_back({'A', 'B', 'C', 'E'});
    board.push_back({'S', 'F', 'C', 'S'});
    board.push_back({'A', 'D', 'E', 'E'});
    exist(board, "ABCB");
}