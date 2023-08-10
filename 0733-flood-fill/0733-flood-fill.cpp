class Solution {
public:
    void solve(vector<vector<int>>& image, int oldcolor, int newcolor, int i, int j){
        if(i<0 || j<0 || i==image.size() || j==image[0].size() || image[i][j] != oldcolor || image[i][j] == newcolor)
            return;
        
        image[i][j]=newcolor;
        
        int delrow[]={1, 0, -1, 0};
        int delcol[]={0, 1, 0, -1};
        
        for(int delta=0;delta<4;delta++){
            solve(image, oldcolor, newcolor, i+delrow[delta], j+delcol[delta]);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];
        if(oldColor == color)
            return image;
        
        solve(image, oldColor, color, sr, sc);
        return image;
    }
};