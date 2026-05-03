class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==0){return 0;}
        else if (nums.size()==1){return nums[0];}
        else if (nums.size()==2){return std::max(nums[0],nums[1]);}
        int last_idx = nums.size() - 1;
        vector<int> money(nums.size(),0);
        int maxm = 0;
        for (int j=last_idx; j>=0; j--){ 
            // for (int k=j+2; k<=last_idx; k++){
            //     if (money[k] > max){max = money[k];} 
            // }            
            if (j<=last_idx - 2){
                maxm = std::max(maxm,money[j+2]);
            }
            money[j] = nums[j] + maxm;
        }
        return *std::max_element(money.begin(),money.end());
    }
};
