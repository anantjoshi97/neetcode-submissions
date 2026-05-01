class KthLargest {
    private:
    std::priority_queue<int,std::vector<int>, std::greater<int>> h;
    int k1;
public:
    KthLargest(int k, vector<int>& nums) {
        k1 = k;        
        int sz = 0;
        //int top = h.top();
        if (k1 > 0){
            for (const int & num : nums){
                if (sz==k1){
                    if (num<=h.top()){continue;}
                    else{
                        h.push(num);
                        h.pop();
                        //top = h.top();
                    }
                }
                else{h.push(num);sz++;}
                
            }
        }
    }
    
    int add(int val) {
        if (h.size()==k1){
            if (val<=h.top()){;}
            else{h.push(val);h.pop();}
        }
        else{h.push(val);}
        return h.top();
        
    }
};
