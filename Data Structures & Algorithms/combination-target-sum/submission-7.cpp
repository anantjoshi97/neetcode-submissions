class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if (nums.size()==0 || target <=0){return {};}
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> output;
        vector<int> vec = {};
        helper(output, nums,target, 0, vec);
        if (output.size()==0){return {};}
        else {return output;}
    }

    void helper(vector<vector<int>> &output, vector<int>& nums, 
        int target, int i, vector<int> &vec){
        int num = nums[i];
        if (target < num){return;}        
        int div = 0;
        //if (target < num){return false;}
        // if (i==nums.size() - 1){
        //     if (target%num==0){
        //         vector<int> vec1 (target/num,num);
        //         vec.insert(vec.end(),vec1.begin(),vec1.end());
        //         combo = true;
        //     }
        // }
        
        for (int j=0; target - j*num > 0; j++){            
            if (j>0){vec.push_back(num);}
            div = j;
            if (i < nums.size()-1){helper(output,nums,target - j*num,i+1,vec);}
                         
        }
        if (target==(div+1)*num){
            div++;
            vec.push_back(num);
            output.push_back(vec);
            std::cout<<"num="<<num<<std::endl;
        }
        for (int j=1; j <= div; j++){vec.pop_back();}

        return;

    }
};
