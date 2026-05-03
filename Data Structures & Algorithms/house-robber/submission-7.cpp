class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0){return 0;}
        else if (nums.size()==1){return nums[0];}
        //else if (nums.size()==2){return std::max(nums[0],nums[1]);}
        int last_idx = nums.size() - 1;
        vector<int> money(nums.size(),0);
        money[last_idx] = nums[last_idx];
        money[last_idx - 1] = std::max(nums[last_idx],nums[last_idx - 1]);
        //int maxm = 0;
        for (int j=last_idx - 2; j>=0; j--){ 
            // for (int k=j+2; k<=last_idx; k++){
            //     if (money[k] > max){max = money[k];} 
            // }            
            
            money[j] = std::max(money[j+1],nums[j] + money[j+2]);
        }
        return *std::max_element(money.begin(),money.end());
    }
};
