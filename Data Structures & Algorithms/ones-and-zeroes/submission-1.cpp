class Solution {
    vector<vector<vector<int>>> dp;
    vector<vector<int>> arr;

    int dfs(int i, int m, int n) {
        if (i == arr.size()) {
            return 0;
        }
        if (m == 0 && n == 0) {
            return 0;
        }
        if (dp[i][m][n] != -1) {
            return dp[i][m][n];
        }

        // not including the current string
        int res = dfs(i + 1, m, n);

        //including the current string
        if (m >= arr[i][0] && n >= arr[i][1]) {
            res = max(res, 1 + dfs(i + 1, m - arr[i][0], n - arr[i][1]));
        }
        dp[i][m][n] = res;
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        arr = vector<vector<int>>(strs.size(), vector<int>(2));

        for (int i = 0; i < strs.size(); ++i) {
            for (char c: strs[i]) {
                arr[i][c - '0'] += 1;
            }
        }

        dp = vector<vector<vector<int>>>(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return dfs(0, m, n);
    }
};