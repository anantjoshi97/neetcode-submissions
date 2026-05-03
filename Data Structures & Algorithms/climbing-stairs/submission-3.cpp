class Solution {

public:
    int climbStairs(int n) {
        if (n<=1){return 1;}
        std::vector<int> ways(n,0);
        ways[n-1] = 1;
        ways[n-2] = 2;
        for (int j=n-3; j>=0; j--){
            ways[j] = ways[j+1] + ways[j+2];
        }
        return ways[0];
    }
};


