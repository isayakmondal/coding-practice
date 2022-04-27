class Solution {
public:
    
    int dp[10010];
    long long soln(int amt, vector<int> &coins){
        if(amt == 0) return 0;
        if(dp[amt]!=-1) return dp[amt];
        long long ans = INT_MAX;
        for(auto & coin: coins){
            
            if(amt-coin>=0)
            ans = min(ans, soln(amt - coin,coins) + 1);
            
        }
        
        return dp[amt]=ans;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        long long ans = soln(amount, coins);
        return ans == INT_MAX ? -1:ans;
    }
};