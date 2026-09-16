class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; ++i) {
            vector<int> new_dp(n, 0);
            new_dp[0] = 1;
            for (int j = 1; j < n; ++j) {
                new_dp[j] = dp[j] + new_dp[j - 1];
            }
            dp = new_dp;
        }
        return dp[n - 1];
    }
};
