class Solution {
    vector<vector<int>> dp;
    int dfs(int i, bool buying, vector<int>& prices) {
        if (i >= prices.size()) {
            return 0;
        }
        // cooldown
        if (dp[i][buying] != INT_MIN) {
            return dp[i][buying];
        }
        int cooldown = dfs(i + 1, buying, prices);
        if (buying) {
            int buy = dfs(i + 1, false, prices) - prices[i];
            dp[i][buying] = max(buy, cooldown);
            return dp[i][buying];
            // return max(buy, cooldown);
        } else {
            int sell = dfs(i + 2, true, prices) + prices[i];
            dp[i][buying] = max(sell, cooldown);
            return dp[i][buying];
            // return max(sell, cooldown);
        }
        return 0;
    }
public:
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2, INT_MIN));
        return dfs(0, true, prices);
    }
};
