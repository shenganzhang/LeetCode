int maxProfit(vector<int>& prices) {
    int min = INT_MAX;
    int max_profit = INT_MIN;
    for (auto &price:prices) {
        if (price < min) min = price;
        if (price - min > max_profit) max_profit = price - min;
    }
    if (max_profit > 0) return max_profit;
    else return 0;