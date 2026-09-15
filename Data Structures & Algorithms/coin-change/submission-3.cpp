class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);

        for (int i = 1; i <= amount; ++i) {
            int min_ = INT_MAX;
            for (int coin: coins) {
                if ((i - coin) >= 0 && dp[i - coin] != INT_MAX) {
                    min_ = min(min_, dp[i - coin] + 1);
                }
            }
            dp[i] = min_;
        }
        if (dp[amount] == INT_MIN || dp[amount] == INT_MAX) {
            return -1;
        }
        return dp[amount];
    }
};
