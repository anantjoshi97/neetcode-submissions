/*

1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

13 14 15 16
9  10 11 12
5  6  7  8
1  2  3  4


for i=0,1,...,n/2 - 1
    swap(grid[i],grid[n-1-i])




for i=0,1,2,...,n-1
    for j=i,i+1,...,n-1
        r1 = i
        c1 = i,i+1,...

        c2 = i
        r2 = i,i+1,...

        std::swap((r1,c1), (r2,c2))

*/




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n<=1){return;}

        //swap rows
        for (int i=0; i<=n/2 - 1; i++){
            std::swap(matrix[i],matrix[n-1-i]);
        }

        //transpose
        for (int i=0; i <=n-1; i++){
            for (int j=i; j<=n-1; j++){
                //int r1 = i;
                //int c1 = j;

                //int c2 = i;
                //int r2 = j;

                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        return;

            

    }
};
