class Solution {
public:
    
    //func(ind, sum_left) -> Min way to get the sum considering upto ind.
    int dp[10005];
    long long func(int sum_left, vector<int> &coins){
        
        if(sum_left==0) return 0;
        if(dp[sum_left]!=-1) return dp[sum_left];
        // if(ind<0) return INT_MAX;
        long long ways = INT_MAX;
        
        for(int i = 0; i<coins.size(); i++){
            
            if(sum_left - coins[i]>=0)
            ways = min(ways, func(sum_left-coins[i], coins)+1);
        }
        
        return dp[sum_left] = ways;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        memset(dp, -1, sizeof(dp));
        long long ans = func(amount, coins);
        return ans == INT_MAX?-1:ans;
    }
};