class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows==0){return -1;}
        int cols = grid[0].size();
        if(cols==0){return -1;}

        
        std::queue <std::pair<int,int>> q;
        //std::vector<std::vector<int>> rotten;
        //std::vector<std::vector<int>> fresh;
        int fresh = 0;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if (grid[i][j] == 1){fresh++;}
                else if(grid[i][j]==2){q.push({i,j});}
            }
        }        
        if(fresh==0){return 0;}
        if(q.empty()){return -1;}
        
        int time = 0;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int j=0; j<4; j++){
                    int r1 = dir[j][0] + r;
                    int c1 = dir[j][1] + c;
                    if (r1 < 0 || c1< 0 || r1 >= rows || c1>=cols){continue;}
                    if (grid[r1][c1]==1){
                        fresh--; 
                        if (fresh==0){return time+1;}
                        grid[r1][c1]=2; 
                        q.push({r1,c1});
                    }
                }

            }
            time++;
        }
        return -1;
    }
};
