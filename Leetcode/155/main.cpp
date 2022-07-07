class MinStack {
public:
    stack<int> s;
    stack<int> mi;

    MinStack() {
    }
    
    void push(int val) {
        if (mi.empty() || val <= mi.top())
            mi.push(val);
        s.push(val);
    }
    
    void pop() {
        if (s.top() == mi.top())
            mi.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mi.top();
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
