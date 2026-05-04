class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image.size()==0 || image[0].size()==0){return image;}
        int rows = image.size();
        int cols = image[0].size();
        if (sr >= rows || sc >= cols){return image;}
        int old_color = image[sr][sc];
        if (color==old_color){return image;}
        helper(image,sr,sc,color,old_color);

        return image;
    }

    void helper(vector<vector<int>>& image, int r, int c, int final_color, int old_color){
        if (r < 0 || c < 0 || r >= image.size() || c>=image[0].size()){return;}        
        
        if (image[r][c] !=old_color){return;}
        else {image[r][c] = final_color;}

        helper(image,r-1,c,final_color,old_color);
        helper(image,r+1,c,final_color,old_color);
        helper(image,r,c-1,final_color,old_color);
        helper(image,r,c+1,final_color,old_color);
        return;
    }

};
/*

g-> r

b b b b
b g b b
b *g g b
b b g g


*/