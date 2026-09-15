class Solution {
public:
    string longestPalindrome(string s) {
        int res_index = 0, res_len = 1;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            // odd length
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > res_len) {
                    res_len = r - l + 1;
                    res_index = l;
                }
                --l;
                ++r;
            }

            // even length
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > res_len) {
                    res_len = r - l + 1;
                    res_index = l;
                }
                --l;
                ++r;
            }
        }
        return s.substr(res_index, res_len);
    }
};
