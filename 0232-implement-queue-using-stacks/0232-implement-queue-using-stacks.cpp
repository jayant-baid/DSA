class MyQueue {
public:
    stack<int> input, output;
    MyQueue() { }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(input.empty() && output.empty())
            return -1;
        
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int ans=output.top();
        output.pop();
        return ans;
        
    }
    
    int peek() {
        if(input.empty() && output.empty())
            return -1;
        
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */