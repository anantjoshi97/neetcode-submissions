class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.size()==0){return -1;}
        if (grid[0].size()==0){return -1;}
        if (grid.size()==1 && grid[0].size()==0){
            if (grid[0][0]==0){return 1;}
            else{return -1;}
        }
        if (grid[0][0]==1 || grid[grid.size()-1][grid[0].size()-1]){return -1;}

        int dir[8][2] = { {1,1},{1,-1},{1,0},{0,1},{0,-1},{-1,0},{-1,-1},{-1,1} };
        std::queue <std::pair<int,int>> q;
        //std::vector<std::vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        q.push({0,0});
        grid[0][0] = 1;
        int length = 1;
        //bool path = false;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                std::pair<int,int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                //if (r==grid.size()-1 && c==grid[0].size()-1){return length;}                

                for (int j=0; j<8; j++){
                    int r1 = r + dir[j][0];
                    int c1 = c + dir[j][1];
                    if (r1 < 0 || c1 < 0 || r1>= grid.size() || c1>= grid.size() 
                        || grid[r1][c1]==1){continue;}
                    else{
                        if (r1==grid.size()-1 && c1 ==grid[0].size()-1){length++; return length;}                  
                        grid[r1][c1] = 1;
                        q.push({r1,c1});                  
                    }
                }

            }
            length++;
        }
        return -1;
    }
};