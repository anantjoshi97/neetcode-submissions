class Solution {
public:
    
    void helper(std::vector<int> vec, vector<vector<int>> &output, int i, vector<int> &nums){        
        std::vector<int> vec2 = vec;
        vec2.push_back(nums[i]);

        if (i==nums.size() - 1){
            output.push_back(vec);
            output.push_back(vec2);
            return;
        }

        helper(vec,output,i+1,nums);
        helper(vec2,output,i+1,nums);

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size()==0){return {{}};}
        vector<vector<int>> output;
        int i=0;
        std::vector<int> vec = {};
        helper(vec,output,i,nums);
        return output;        
        
    }

    

};
