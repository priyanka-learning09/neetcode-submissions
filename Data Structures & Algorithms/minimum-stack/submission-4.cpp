class MinStack {
public:
    MinStack() {
        
    }
    stack<int> st;
    stack<int> minst;
    
    void push(int val) {
        st.push(val);
        if(minst.empty() || minst.top()>= val )
        {
            minst.push(val);
        }
        
    }
    
    void pop() {
        if(st.empty())
        {
            return;
        }
        if(st.top()==minst.top())
        {
            st.pop();
            minst.pop();
            return;
        }
        st.pop();
      
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
