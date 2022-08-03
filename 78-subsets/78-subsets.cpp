class Solution {
public:
    
    vector<vector<int>> ans;
    
    void subs(vector<int> v, int i, vector<int>&nums){
        
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[i]);
        subs(v,i+1,nums);
        v.pop_back();
        subs(v,i+1,nums);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> v;
        subs(v,0,nums);
        return ans;
    }

};