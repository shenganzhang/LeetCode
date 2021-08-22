int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> map;
    map[0] = 1;
    int pre = 0;
    int cnt = 0;
    for (const auto & num:nums) {
        pre += num;
        if (map.find(pre - k) != map.end()) cnt += map[pre - k];
        map[pre]++;
    }
    return cnt;
}