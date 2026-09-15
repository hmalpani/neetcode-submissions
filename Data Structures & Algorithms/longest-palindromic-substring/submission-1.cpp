class Solution {
public:
    string longestPalindrome(string s) {
        int res_index = 0, res_len = 1;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                dp[i - 1][i] = true;
                res_index = i - 1;
                res_len = 2;
            }
        }
        for (int i = 2; i < n; ++i) {
            if (s[i] == s[i - 2]) {
                dp[i - 2][i] = true;
                res_index = i - 2;
                res_len = 3;
            }
        }

        for (int size = 4; size <= n; ++size) {
            for (int start = 0; start + size <= n; ++start) {
                int end = start + size - 1;
                if (s[start] == s[end] && dp[start + 1][end - 1]) {
                    dp[start][end] = true;
                    if (end - start + 1 > res_len) {
                        res_index = start;
                        res_len = end - start + 1;
                    }
                }
            }
        }
        return s.substr(res_index, res_len);
    }
};
