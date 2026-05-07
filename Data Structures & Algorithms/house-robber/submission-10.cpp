class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (nums.size()==0){return 0;}
        else if (nums.size()==1){return nums[0];}
        else if (nums.size()==2){return std::max(nums[0],nums[1]);}

        std::vector<int> rwd (n,0);
        rwd[n-1] = nums[n-1];
        rwd[n-2] = std::max(nums[n-1],nums[n-2]);

        int r1, r2;
        r1 = nums[n-1];
        r2 = std::max(nums[n-1],nums[n-2]);

        for (int i=n-3; i>=0; i--){
            rwd[i] = std::max(rwd[i+1],nums[i]+rwd[i+2]);
            r1 = std::max(r2,nums[i] + r1);
            std::swap(r1,r2);
        }
        return r2;
    }
       
};
