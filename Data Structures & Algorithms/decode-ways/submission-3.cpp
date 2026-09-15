class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp1 = 0, dp2 = 1;
        if (s[n - 1] != '0') {
            dp1 = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] == '0') {
                dp2 = dp1;
                dp1 = 0;
                continue;
            }
            int temp = dp1;
            int num = ((s[i] - '0') * 10) + (s[i + 1] - '0');
            if (num <= 26) {
                temp += dp2;
            }
            dp2 = dp1;
            dp1 = temp;
        }
        return dp1;
    }
};
