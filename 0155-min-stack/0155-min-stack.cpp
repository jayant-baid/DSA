class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() {
        mini=0;
    }
    
    void push(int val) {
        
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val < mini){
                st.push(2*(long long)val-mini);
                mini=val;
            }
            else
                st.push(val);
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        
        if(st.top()<mini)
            mini=2*mini-st.top();
        
        st.pop();
        
    }
    
    int top() {
        if(st.empty())
            return -1;
        if(st.top() < mini)
            return mini;
        return st.top();
    }
    
    int getMin() {
        if(st.empty())
            return -1;
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