class MinStack {
private:
    std::stack<int> minStack;
    std::stack<int> stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        val = (!minStack.empty() ? min(val, minStack.top()) : val);
        minStack.push(val);
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
