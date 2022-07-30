class Solution {
public:
    
    vector<vector<int>> ans;
    
    void permute_rec(vector<int> ds, int hsh[], vector<int> &nums){
        
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            
            if(!hsh[i]){
            ds.push_back(nums[i]);
            hsh[i] = 1;
            permute_rec(ds, hsh, nums);
            ds.pop_back();
            hsh[i]=0;
            }
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> ds;
        int hsh[nums.size()];
        for(int i=0;i<nums.size();i++){
            hsh[i]=0;
        }
        
        permute_rec(ds, hsh, nums);
        
        return ans;
        
    }
};