class Solution {
public: 
    int dp[200][200]{};
    
   int dfs(int i, int j, int prev, int m, int n, vector<vector<int>>& matrix){
        
        if(i<0 || j<0) return 0;
        if(i>=m || j>=n) return 0;
        if(matrix[i][j]<=prev) return 0;
       if(dp[i][j]) return dp[i][j];
        
        int a,b,c,d;
        
        
         a = dfs(i+1,j, matrix[i][j],m,n, matrix);
         b = dfs(i,j+1,matrix[i][j],m,n, matrix);
         c = dfs(i-1,j,matrix[i][j],m,n, matrix);
         d = dfs(i ,j-1,matrix[i][j],m,n, matrix);
        
        return dp[i][j]= max(a,max(b,max(c,d)))+1;
        
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int ct = 0;
        for(int i = 0; i < m; i++){
            for( int j = 0; j < n; j++){
                
                ct = max(ct,dfs(i,j,-1,m,n, matrix));
            }
        }
          
        return ct;
        
    }
};