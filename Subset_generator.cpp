//Only class and function
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> v;
    
    void subsGenerator(vector<int> &subset, int i,vector<int> &nums){
        
        if(i==nums.size()){
            v.push_back(subset);
            return;
        }
        
        subsGenerator(subset,i+1,nums);
        
        subset.push_back(nums[i]);
        subsGenerator(subset,i+1,nums);
        subset.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> temp;
        subsGenerator(temp,0,nums);
        return v;
    }
};