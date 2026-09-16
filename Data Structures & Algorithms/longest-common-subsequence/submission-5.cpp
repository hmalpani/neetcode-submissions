class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.length() < text2.length()) {
            swap(text1, text2);
        }
        int m = text1.length();
        int n = text2.length();
        vector<int> dp(n + 1, 0);
        for (int i = m - 1; i >= 0; --i) {
            int prev = 0;
            for (int j = n - 1; j >= 0; --j) {
                int temp = dp[j];
                if (text1[i] == text2[j]) {
                    dp[j] = 1 + prev;
                } else {
                    dp[j] = max(dp[j], dp[j + 1]);
                }
                prev = temp;
            }
        }
        return dp[0];
    }
};
