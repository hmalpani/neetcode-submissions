class Solution {
public:
    bool isValid(string &s) {
        int open = 0;
        for (char c: s) {
            open += (c=='(') ? 1 : -1;
            if (open < 0) return false;
        }
        return open==0;
    }
    void generate(string s, vector<string> &ans, int n) {
        if (s.length() == 2*n) {
            if (isValid(s)) ans.push_back(s);
            return;
        }
        generate(s+'(', ans, n);
        generate(s+')', ans, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate("", ans, n);
        return ans;
    }
};
