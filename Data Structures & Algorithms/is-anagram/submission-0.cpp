class Solution {
public:
    bool isAnagram(string s, string t) {
        int alphabet[26] = {0};
        int n = s.length();
        if (t.length() != n) {
            return false;
        }
        for (int i=0; i<n; ++i) {
            ++alphabet[s[i] - 'a'];
            --alphabet[t[i] - 'a'];
        }
        for (int i=0; i<26; ++i) {
            if (alphabet[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
