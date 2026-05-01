class KthLargest {
    private:
    std::priority_queue<int,std::vector<int>, std::greater<int>> h;
    int k1;
public:
    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        for (const int & num : nums){
            h.push(num);
            if (h.size()>k1){
                h.pop();
            }
        }
    }
    
    int add(int val) {
        //int k = h.size();
        h.push(val);
        if (h.size()>k1){
            h.pop();
        }
        return h.top();
    }
};
