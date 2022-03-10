class Solution {
public:
    
    
    void dfs(int i, int j, int n, int m, int newColor, int curColor, vector<vector<int>>& image ){
        
        if(i<0 || j<0) return;
        if(i>=n || j>=m) return;
        if(curColor!=image[i][j]) return;
        
        image[i][j] = newColor;
        dfs(i+1,j,n,m,newColor,curColor,image);
        dfs(i,j+1,n,m,newColor,curColor,image);
        dfs(i-1,j,n,m,newColor,curColor,image);
        dfs(i,j-1,n,m,newColor,curColor,image);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int curColor = image[sr][sc];
        
        if(curColor == newColor) return image;
        dfs(sr,sc,n,m,newColor,curColor,image);
     
        return image;
    }
};