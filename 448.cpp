vector<int> findDisappearedNumbers(vector<int>& nums) {
    unordered_set<int> mem;
    for (const int& num:nums) {
        mem.insert(num);
    }
    int n = nums.size();
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (!mem.count(i)) result.push_back(i);
    }
    return result;
}