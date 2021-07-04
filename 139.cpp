bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> set;
    for (const auto & word : wordDict) {
        set.insert(word);
    }

    vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i < dp.size() + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && set.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}