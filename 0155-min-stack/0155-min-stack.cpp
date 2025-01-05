class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(long long val) {
        if(st.empty())
        {
            mini=val;
            st.push(val);
        }
        else 
        {
            if(val<mini)
            {
                st.push(2*val-mini);
                mini=val;
            }
            else
            {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty())return;
        long long val=st.top();
        st.pop();
        if(val<mini)
        {
            mini=2*mini-val;
        }
    }
    
    long long top() {
        long long val=st.top();
        if(val<mini)
        {
            return mini;
        }
        return val;
    }
    
    long long getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */