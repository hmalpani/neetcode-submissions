class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<int> dp(n + 1, 0);
        for (int i = m - 1; i >= 0; --i) {
            vector<int> newdp(n + 1, 0);

            for (int j = n - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    newdp[j] = 1 + dp[j + 1];
                } else {
                    newdp[j] = max(dp[j], newdp[j + 1]);
                }
            }
            dp = newdp;
        }
        return dp[0];
    }
};
