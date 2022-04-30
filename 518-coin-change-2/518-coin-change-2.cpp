class Solution {
public:
    
       int dp[305][10010];
    long long soln(int index, int amt, vector<int> &coins){
        
       
        if(amt==0) return 1;
        if(index < 0) return 0;
        int ways = 0;
        if(dp[index][amt]!= -1) return dp[index][amt];
        for(int coin_amt = 0; coin_amt <= amt; coin_amt+=coins[index]){
            if(amt-coin_amt>=0)
            ways+=soln(index-1,amt-coin_amt,coins);
        }
        
        return dp[index][amt] = ways;
    }
    
    int change(int amount, vector<int>& coins) {
        
          memset(dp, -1, sizeof(dp));
        long long ans = soln(coins.size()-1,amount, coins);
        return ans;
    }
};