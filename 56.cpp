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

class IntervalCompare {
public:
    bool operator()(const vector<int> &interval1, const vector<int> &interval2) {
        // Compare on basis of roll number
        if (interval1[0] < interval2[0]) return true;
        if (interval1[0] > interval2[0]) return false;
        if (interval1[1] < interval2[1]) return true;
        return false;
    }
};

class Solution {
public:

    bool isMergeable(const vector<int> &interval1, const vector<int> &interval2) {
        if (interval1[0] > interval2[1]) return false;
        if (interval1[1] < interval2[0]) return false;
        return true;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        IntervalCompare comparator;
        sort(intervals.begin(), intervals.end(), comparator);
        vector<vector<int>> results;
        for (int i = 0; i < intervals.size(); ++i) {
            if (i == 0 || !isMergeable(results.back(), intervals[i])) results.push_back(intervals[i]);
            else {
                auto result = intervals[i];
                if (isMergeable(result, results.back())) {
                    result[0] = min(result[0], results.back()[0]);
                    result[1] = max(result[1], results.back()[1]);
                    results.pop_back();
                }
                results.push_back(result);
            }
        }
        return results;
    }
};