class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        if (rows==0){return 0;}
        int cols = grid[0].size();
        if (cols==0){return 0;}
        int count = 0;

        for (int r = 0; r < rows; r++){
            for (int c=0; c < cols; c++){
                if (grid[r][c]=='1'){helper(grid,r,c); count++;}
            }
        }
        return count;

    }

    void helper(vector<vector<char>>& grid, int r, int c){
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()){return;}
        if (grid[r][c]!='1'){return;}

        grid[r][c]='x';
        helper(grid,r-1,c);
        helper(grid,r+1,c);
        helper(grid,r,c+1);
        helper(grid,r,c-1);
        return;

    }
};
