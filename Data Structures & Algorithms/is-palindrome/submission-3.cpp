class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while (i<j && i<s.length() && j>=0) {
            while (!((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') || (s[i] >='0' && s[i]<='9'))) {
                ++i;
            }
            while (!((tolower(s[j]) >= 'a' && tolower(s[j]) <= 'z') || (s[j] >='0' && s[j]<='9'))) {
                --j;
            }
            if (i>=s.length() || j<0) {
                return true;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};
