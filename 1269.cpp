#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
// tricks: rolling array
int numWays(int steps, int arrLen) {
    int colNum = min(steps, arrLen);
    const int typo = 1000000007;
    vector<int> array(colNum, 0);
    array[0] = 1;
    for (int i = 1; i < steps + 1; i++) {
        vector<int> next(colNum, 0);
        for (int j = 0; j < colNum; j++) {
            if (j == 0) {
                next[j] = (array[j] + array[j + 1]) % typo;
            } else if (j == colNum - 1) {
                next[j] = (array[j - 1] + array[j]) % typo;
            } else {
                next[j] = (array[j - 1] + array[j] + array[j + 1]) % typo;
            }
        }
        array = next;
    }
    return array[0];
//    vector<vector<int>> table(steps + 1, vector<int>(arrLen, 0));
//    table[0][0] = 1;
//    const int typo = 1000000007;
//    for (int i = 1; i <= steps; i++) {
//        for (int j = 0; j < arrLen; j++) {
//            if (j == 0) {
//                table[i][j] = (table[i - 1][j] + table[i - 1][j + 1]) % typo;
//            } else if (j == arrLen - 1) {
//                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % typo;
//            } else {
//                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j] + table[i - 1][j + 1]) % typo;
//            }
//        }
//    }

//    return (table[steps][0]);
}

int main() {
    cout << numWays(2, 4);
}
