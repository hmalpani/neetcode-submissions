class Solution {
    bool solve(int start, string s, vector<optional<bool>>& dp, unordered_set<string>& dict) {
        if (start >= s.length()) {
            return true;
        }
        if (dp[start].has_value()) {
            return dp[start].value();
        }

        string cur = "";
        for (int i = start; i < s.length(); ++i) {
            cur += s[i];
            // if (dict.contains(cur)) {
            //     dp[start] = solve(i + 1, s, dp, dict);
            // }
            if (dict.contains(cur) && solve(i + 1, s, dp, dict)) {
                dp[start] = true;
                return true;
            }
        }
        dp[start] = false;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<optional<bool>> dp(s.length(), nullopt);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(0, s, dp, dict);
    }
};
