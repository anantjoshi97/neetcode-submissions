class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m<=0 || n<=0){return 0;}
        if (m==1 || n==1){return 1;}
        
        vector<vector<int>> paths (m, vector<int> (n,0));
        int r = m-1;
        int c = n-1;
        for (int j=0; j<=c; j++){
            paths[r][j] = 1;
        }
        for (int j=0; j<=r-1; j++){
            paths[j][c] = 1;
        }
        r--;
        c--;
        while (r>=0 && c>=0){
            for(int j=c; j>=0; j--){
                paths[r][j] = paths[r+1][j] + paths[r][j+1];
            }
            for(int j=r-1; j>=0; j--){
                paths[j][c] = paths[j][c+1] + paths[j+1][c];
            }
            r--;
            c--;
        }
        return paths[0][0];
    }
};
