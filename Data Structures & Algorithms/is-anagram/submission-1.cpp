class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> chars(26, 0);

        for (int i = 0; i < s.length(); ++i) {
            chars[s[i] - 'a'] += 1;
            chars[t[i] - 'a'] -= 1;
        }
        for (int i = 0; i < 26; ++i) {
            if (chars[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
