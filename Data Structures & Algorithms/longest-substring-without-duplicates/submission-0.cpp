class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l=0, ans = 0;
        int n = s.length();
        for (int i=0; i<n; ++i) {
            if (mp.find(s[i]) != mp.end()) {
                l = max(mp[s[i]] + 1, l);
            }
            mp[s[i]] = i;
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};
