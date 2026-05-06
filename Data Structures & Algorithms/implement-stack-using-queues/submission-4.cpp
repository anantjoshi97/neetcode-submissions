class MyStack {
    std::queue<int> q1, q2;
public:
    MyStack() {
        ;
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            int y = q1.front();
            q2.push(y);
            q1.pop();
        }
        std::swap(q1,q2);
    }
    
    int pop() {
        if(!q1.empty()){int y = q1.front(); q1.pop(); return y;}
        return -1;
    }
    
    int top() {
        if(!q1.empty()){return q1.front();}
        return -1;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */