class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        // if (rows==0){
        //     return false;
        // }
        int columns = matrix[0].size();
        // if (columns==0){return false;}

        // int r = rows - 1;
        // int c = columns - 1;

        auto idx = [&](int num1){
            return pair<int,int> {(num1)/columns, (num1)%columns};
        };

        // if(matrix[r][c] < target || matrix [0][0] > target){
        //     return false;
        // }

        int l=0;
        int r=rows*columns - 1;

        while(l <=r){
            int mid = l + (r-l)/2;
            std::pair idx_mid = idx(mid);
            int num_mid = matrix[idx_mid.first][idx_mid.second];
            if (num_mid == target){return true;}
            else if(num_mid > target){r = mid - 1;}
            else if (num_mid < target){l = mid + 1;}
        }

        return false;

    }
};
