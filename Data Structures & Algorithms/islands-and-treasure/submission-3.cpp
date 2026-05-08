class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& maps) {
    //vector<vector<int>> maps = grid;
    int rows = maps.size();
    int cols = maps[0].size();
    int land = 2147483647;

    std::vector<std::pair<int,int>> trs;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if (maps[i][j]==0){trs.push_back({i,j});}
        }
    }
    if(trs.size()==0){return;}

    std::queue <std::pair<int,int>> q;
    for (std::pair<int,int> &cell : trs){
        q.push(cell);
    }
    int nbrs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    //std::vector<int> wave_front(trs.size(),1);
    int path_length = 0;
    while(!q.empty()){
        int sz = q.size();
        path_length++;
        for (int i=0; i<sz; i++){
            std::pair<int,int> curr = q.front();
            int r_trs = curr.first;
            int c_trs = curr.second;
            q.pop();
            for (int j=0; j<4; j++){
                int r_nbr = r_trs + nbrs[j][0];
                int c_nbr = c_trs + nbrs[j][1];
                if(r_nbr < 0 || c_nbr < 0 || r_nbr >= rows|| c_nbr >= cols){continue;}
                // if (map[r_nbr][c_nbr]!=-1 && map[r_nbr][c_nbr]!=0){
                //     if (map[r_nbr][c_nbr] < path_length){continue;}
                //     else{wave_front[i]++;q.push({r_nbr,c_nbr});}
                // }
                if (maps[r_nbr][c_nbr]==land){
                    q.push({r_nbr,c_nbr});
                    maps[r_nbr][c_nbr]= path_length;
                }
            }
            
            
        }
    }

}
};
