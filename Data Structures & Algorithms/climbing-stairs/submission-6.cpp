class Solution {
vector<int> ways;
public:
    int climbStairs(int n) {
        if (n<=2){return n;}
        //if(n==2){return }
        //std::vector<int> ways(n,0);
        std::unordered_map<int,int> ways;
        return helper(0,n,ways); 
        
    }

    int helper(int j, int &n, unordered_map<int,int> & ways){
        if (ways.count(j)){;}       
        else if (j<=n && j >= n-2){ways[j] = n-j;}
        else {ways[j] = helper(j+1,n,ways) + helper(j+2,n,ways);}
        return ways[j];
    }
};


