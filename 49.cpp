#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>
#include <algorithm>
#include <stack>
#include <utility>
#include <set>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> results;
    map<vector<char>, int> map;
    for (string & str: strs) {
        vector<char> temp;
        for (char & chr: str) {
            temp.push_back(chr);
        }
        sort(temp.begin(), temp.end());
        if (map.find(temp) == map.end()) {
            map[temp] = results.size();
            results.push_back(vector<string>({str}));
        } // not mapped
        else {
            int index = map[temp];
            results[index].push_back(str);
        }
    }
    return results;
}

int main() {
    map<vector<char>, int> s;
    vector<char> temp({'a','b'});
    vector<char> temp1({'b','a'});
    s[temp] = 1;
    cout << s[temp1];
}