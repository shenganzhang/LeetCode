#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;
// sliding windows
int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> map;
    int start = 0;
    int length = 0;
    for (int j = 0; j < s.length(); j++) {
        if (map.find(s[j]) != map.end() && map[s[j]] >= start) {
            start = map[s[j]] + 1;
        }
        map[s[j]] = j;
        length = max(length, j - start + 1);
    }
    return length;
}