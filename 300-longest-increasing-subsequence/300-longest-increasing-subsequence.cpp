class Solution {
public:
   
    int dp[2515];
    
    int lis(int i, vector<int> &nums){
        
        if(dp[i]!=-1) return dp[i];
        int cost = 1;
        
        for(int j = 0; j < i; j++){
            
            if(nums[j]<nums[i])
            cost = max(cost, lis(j, nums)+1);
        }
        
        return dp[i] = cost;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        
        memset(dp, -1, sizeof(dp));
        
        int cost = 0;
        for(int i = 0; i<nums.size(); i++){
            
            cost = max(cost, lis(i,nums));
            
        }
        return cost;
        
    }
};