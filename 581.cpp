int findUnsortedSubarray(vector<int>& nums) {
    int max = INT_MIN;
    int right = -1;
    int min = INT_MAX;
    int left = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (max <= nums[i]) max = nums[i];
        else right = i;
        if (min >= nums[nums.size() - i - 1]) min = nums[nums.size() - i - 1];
        else left = nums.size() - i - 1;
    }
    if (right == -1) return 0;
    else return right - left + 1;
}