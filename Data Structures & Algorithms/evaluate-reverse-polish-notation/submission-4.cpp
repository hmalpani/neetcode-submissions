class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+") {
                int o1 = st.top();
                st.pop();
                int o2 = st.top();
                st.pop();
                st.push(o1 + o2);
            } else if (tokens[i] == "-") {
                int o1 = st.top();
                st.pop();
                int o2 = st.top();
                st.pop();
                st.push(o2 - o1);
            } else if (tokens[i] == "*") {
                int o1 = st.top();
                st.pop();
                int o2 = st.top();
                st.pop();
                st.push(o1 * o2);
            } else if (tokens[i] == "/") {
                int o1 = st.top();
                st.pop();
                int o2 = st.top();
                st.pop();
                st.push(o2 / o1);
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
