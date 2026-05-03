class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> &grid = obstacleGrid;
        int rows = obstacleGrid.size();
        if (rows==0){return 0;}
        int cols = obstacleGrid[0].size();
        if (cols==0){return 0;}
        if (grid[rows-1][cols-1]==1){return 0;}
        vector<int> data(cols,0);
        data[cols-1] = 1;
        int r = rows- 1;
        while(r>=0){
            for (int c=cols-1; c>=0; c--){
                if (grid[r][c] == 1){data[c] = 0; continue;}
                if (c == cols - 1){
                    continue;                    
                }
                //if (r == rows-1){data[c] = data[c+1];}
                //else{
                    data[c] = data[c] + data[c+1];
                    //;}
            }
            r--;
        }
        return data[0];
        
    }
};