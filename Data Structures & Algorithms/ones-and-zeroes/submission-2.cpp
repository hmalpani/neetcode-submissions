class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> arr = vector<vector<int>>(strs.size(), vector<int>(2, 0));
        for (int i = 0; i < strs.size(); ++i) {
            for (char c: strs[i]) {
                arr[i][c - '0'] += 1;
            }
        }
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = 1; i <= strs.size(); ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= arr[i - 1][0] && k>= arr[i - 1][1]) {
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - 1][j - arr[i - 1][0]][k - arr[i - 1][1]]);
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }
};