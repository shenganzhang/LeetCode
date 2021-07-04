int majorityElement(vector<int>& nums) {
    int majority = INT_MIN;
    int count = 0;
    for (const auto & num : nums) {
        if (num == majority) count++;
        else {
            if (count != 0) count--;
            else {
                majority = num;
                count++;
            }
        }
    }
    return majority;
}