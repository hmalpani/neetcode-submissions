class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for (int i=0; i<n; ++i) {
            ans = ans + to_string(strs[i].length()) + "#" + strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        for (int i=0; i<n;) {
            int x = 0;
            while (s[i] != '#') {
                x = x*10 + (s[i] - '0');
                ++i;
            }
            ++i;
            string temp = s.substr(i, x);
            i += x;
            ans.push_back(temp);
        }
        return ans;
    }
};
