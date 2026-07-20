class MinStack {
    stack<int> st, cur_min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        int temp = INT_MAX;
        if (!cur_min.empty()) {
            temp = cur_min.top();
        }
        cur_min.push(min(val, temp));
    }
    
    void pop() {
        st.pop();
        cur_min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return cur_min.top();
    }
};
