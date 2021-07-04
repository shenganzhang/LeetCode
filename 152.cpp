int maxProduct(vector<int>& nums) {
    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int tempMaxProd = maxProd;
        int tempMinProd = minProd;
        maxProd = max(tempMaxProd * nums[i], max(nums[i], tempMinProd * nums[i]));
        minProd = min(tempMaxProd * nums[i], min(nums[i], tempMinProd * nums[i]));
        result = max(result, maxProd);
    }
    return result;
}