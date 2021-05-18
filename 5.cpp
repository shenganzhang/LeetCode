#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

//expand from center
class Solution {
public:
    pair<int, int> expand(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            auto[l1, r1] = expand(s, i, i);
            auto[l2, r2] = expand(s, i, i + 1);
            if (r1 - l1 > end - start) {
                start = l1;
                end = r1;
            }
            if (r2 - l2 > end - start) {
                start = l2;
                end = r2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// dp
class AnotherSolution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        string best;
        int strLength = s.length();
        vector<vector<bool>> dp(strLength, vector<bool>(strLength, false));
        for (int r = 0; r < strLength; r++) {
            for (int l = 0; l < strLength; l++) {
                if (r < l) {
                    continue;
                } else if (r == l) {
                    dp[l][r] = true;
                } else if (r == (l + 1)) {
                    if (s[l] == s[r]) {
                        dp[l][r] = true;
                    }
                } else {
                    if (s[l] == s[r] && dp[l + 1][r - 1]) {
                        dp[l][r] = true;
                    }
                }
                if (dp[l][r]) {
                    if ((r - l) > (end - start)) {
                        end = r;
                        start = l;
                        best = s.substr(start, end - start + 1);
                    }
                }
            }
        }
        return best;
    }
};