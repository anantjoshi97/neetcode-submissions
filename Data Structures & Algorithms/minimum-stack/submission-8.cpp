class MinStack {
    int min_ele;
    std::stack<int> stk;
    std::stack<int> min_stk;
    //bool first_push;
public:
    MinStack() {;}
    
    void push(int val) {        
        if(stk.empty()){
            stk.push(val);
            min_stk.push(val);
        }
        else{
            min_stk.push(std::min(val,min_stk.top()));
            stk.push(val);
        }
    }
    
    void pop() {
        if (!stk.empty()){stk.pop();min_stk.pop();}
    }
    
    int top() {
        if (!stk.empty()){return stk.top();}
    }
    
    int getMin() {
        if (!stk.empty()){return min_stk.top();}
    }
};
