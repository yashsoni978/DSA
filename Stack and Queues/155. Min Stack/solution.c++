class MinStack {
public:
    stack<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) st.push({value, value});
        else st.push({value, min(st.top().second, value)}); 
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//1 and 2n

class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push(value);
        }
        else if(value >= mini) st.push(value);
        else{
            st.push(2LL* value - mini);
            mini = value;
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini) mini = 2LL* mini - x;
        if(st.empty()) mini = INT_MAX;
    }
    
    int top() {
        long long x = st.top();
        if(x < mini) return mini;
        return x;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//1 and n