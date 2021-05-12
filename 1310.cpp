#include <iostream>
#include <vector>

using namespace std;

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    vector<int> preComp(arr.size());
    int lastResult = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (i != 0) {
            preComp[i] = (unsigned int) arr[i] ^ (unsigned int) lastResult;
        } else {
            preComp[i] = arr[i];
        }
        lastResult = preComp[i];
    }
    vector<int> results(queries.size());
    for (int i = 0; i < queries.size(); i++) {
        int start;
        start = queries[i][0];
        int end;
        end = queries[i][1];
        if (start == 0) {
            results[i] = (unsigned int) preComp[end];
        }
        else {
            results[i] = (unsigned int) preComp[start - 1] ^ (unsigned int) preComp[end];
        }
    }
    return results;
}

int main() {
    int x[4] = {1, 3, 4, 8};
    vector<int> arr(x, x + sizeof(x) / sizeof(x[0]));
    vector<vector<int>> queries;
    queries.push_back(vector<int>({0, 1}));
    queries.push_back(vector<int>({1, 2}));
    queries.push_back(vector<int>({0, 3}));
    queries.push_back(vector<int>({3, 3}));
    xorQueries(arr, queries);
}
