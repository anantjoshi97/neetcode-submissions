class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n==0){return 0;}
        else if (n==1){return cost[0];}
        else if (n==2){return min(cost[0],cost[1]);}
        vector<int> dp(n,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<cost.size();i++){
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return min(dp[n-1],dp[n-2]);
    }
};
