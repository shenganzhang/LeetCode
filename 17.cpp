#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

void backtrack(vector<string> &combinations, const string &digits,
               const unordered_map<char, string> &phoneMap, string &combination,
               int index) {
    if (index == digits.length()) {
        combinations.push_back(combination);
    } else {
        auto digit = digits[index];
        auto string = phoneMap.at(digit);
        for (char &letter : string) {
            combination.push_back(letter);
            backtrack(combinations, digits, phoneMap, combination, index + 1);
            combination.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> combinations;
    if (digits.empty()) {
        return combinations;
    }
    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    string combination;
    int index = 0;
    backtrack(combinations, digits, phoneMap, combination, index);
    return combinations;


//    unordered_map<char, vector<char>> map = {
//            {'2', vector<char>({'a', 'b', 'c'})},
//            {'3', vector<char>({'d', 'e', 'f'})},
//            {'4', vector<char>({'g', 'h', 'i'})},
//            {'5', vector<char>({'j', 'k', 'l'})},
//            {'6', vector<char>({'m', 'n', 'o'})},
//            {'7', vector<char>({'p', 'q', 'r', 's'})},
//            {'8', vector<char>({'t', 'u', 'v'})},
//            {'9', vector<char>({'w', 'x', 'y', 'z'})}
//    };
//    if (digits.length() == 0) {
//        return vector<string>({});
//    }
//    if (digits.length() == 1) {
//        vector<string> results;
//        for (char &i : map[digits[0]]) {
//            results.emplace_back(1, i);
//        }
//        return results;
//    }
//    int length = 1;
//    for (char &digit : digits) {
//        length *= map[digit].size();
//    }
//    vector<string> results(length, "");
//    for (int digit_index = 0; digit_index < digits.length() - 1; digit_index++) {
//        int i = 0;
//        for (char &letter : map[digits[digit_index]]) {
//            for (int j = 0; j < length/map[digits[digit_index]].size(); j++){
//                results[i].push_back(letter);
//                i++;
//            }
//        }
//        length /= map[digits[digit_index]].size();
//    }
//
//    char last_digit = digits[digits.length() - 1];
//    int j = 0;
//    for (int i = 0; i < length; i++) {
//        for (char &letter : map[last_digit]) {
//            results[j].push_back(letter);
//            j++;
//        }
//    }
//    return results;
}


int main() {
    string s = "234";
    letterCombinations(s);
}