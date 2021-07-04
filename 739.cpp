vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> temp;
    vector<int> results(temperatures.size());
    for (int i = 0; i < temperatures.size(); ++i) {
        if (temp.empty()) temp.push(i);
        else {
            while (!temp.empty() && temperatures[i] > temperatures[temp.top()]) {
                results[temp.top()] = i - temp.top();
                temp.pop();
            }
            temp.push(i);
        }
    }
    return results;
}