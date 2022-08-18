class Solution {
public:
    
 
    
    bool canJump(vector<int>& nums) {
    
     int n=nums.size();
        int reach = 0;
        for(int i=0;i<n;i++){
            
            
            if(i>reach) return false;
            if(i+nums[i]>reach){
                reach=i+nums[i];
            }
            
            
            }
            
        return true;
        }
        

};