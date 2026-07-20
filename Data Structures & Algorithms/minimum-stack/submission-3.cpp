class MinStack {
    long min_val;
    stack<long> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(0);
            min_val = val;
        } else {
            st.push(val - min_val);
            if (val < min_val) {
                min_val = val;
            }
        }
    }
    
    void pop() {
        if (st.empty()) {
            return;
        }
        long top = st.top();
        st.pop();
        if (top < 0) {
            min_val = min_val - top;
        }
    }
    
    int top() {
        long top = st.top();
        if (top > 0) {
            return top + min_val;
        }
        return (int)min_val;
    }
    
    int getMin() {
        return (int)min_val;
    }
};
