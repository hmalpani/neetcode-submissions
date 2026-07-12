class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for (int i=0; i<n; ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int x1 = st.top();
                st.pop();
                int x2 = st.top();
                st.pop();
                st.push(calc(x1, x2, tokens[i][0]));
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
    int calc(int x1, int x2, char op) {
        int ans=0;
        if (op == '+') ans = (x1+x2);
        else if (op == '-') ans = (x2-x1);
        else if (op == '/') ans = (x2/x1);
        else if (op == '*') ans = (x2*x1);
        return ans;
    }
};
