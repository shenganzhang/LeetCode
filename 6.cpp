#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        bool down = true;
        int pos = 0;
        vector<vector<char>> table(numRows, vector<char>());
        for (char & i : s) {
            table[pos].push_back(i);
            if (pos == 0) down = true;
            if (pos == numRows - 1) down = false;
            if (down) pos++;
            else pos--;
        }
        string result;
        for (int i = 0; i < numRows; i++) {
            for (char & j : table[i]) {
                result += j;
            }
        }
        return result;
    }
};
