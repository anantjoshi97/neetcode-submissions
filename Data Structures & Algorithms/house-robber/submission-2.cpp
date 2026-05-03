class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0){return 0;}
        else if (nums.size()==1){return nums[0];}
        else if (nums.size()==2){return std::max(nums[0],nums[1]);}
        int last_idx = nums.size() - 1;
        vector<int> money(nums.size(),0);
        for (int j=last_idx; j>=0; j--){
            int max = 0;
            for (int k=j+2; k<=last_idx; k++){
                if (money[k] > max){max = money[k];} 
            }
            money[j] = nums[j] + max;
        }
        return *std::max_element(money.begin(),money.end());
    }
};
