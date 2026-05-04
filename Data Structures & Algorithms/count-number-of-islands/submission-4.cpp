class Solution {
    int dir[2][2][2] = {{ {1,0}, {-1,0}},{ {0,1},{0,-1}}};
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size();
        if (rows==0){return 0;}
        int cols = grid[0].size();
        if (cols==0){return 0;}
        int count = 0;

        for (int r = 0; r < rows; r++){
            for (int c=0; c < cols; c++){
                if (grid[r][c]=='1'){helper_bfs(grid,r,c); count++;}
            }
        }
        return count;

    }

    void helper_bfs(vector<vector<char>>& grid, int r, int c){
        std::queue<std::vector<int>> q;
        grid[r][c]='x';
        q.push({r,c});
        while(!q.empty()){
            std::vector<int> curr = q.front();
            r = curr[0];
            c = curr[1];
            q.pop();
            for (int i1 =0; i1<=1; i1++){
                for(int j1=0; j1<=1; j1++){
                    int r1 = r + dir[i1][j1][0];
                    int c1 = c + dir[i1][j1][1];
                    if (r1 < 0 || c1 < 0 || r1 >= grid.size() || c1 >= grid[0].size()){continue;}
                    else{
                        if (grid[r1][c1]=='1'){q.push({r1,c1}); grid[r1][c1]='x';}
                        else{continue;}
                    }
                }
            }
        }
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
