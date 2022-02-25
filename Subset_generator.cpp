//Only class and function
#include<bits/stdc++.h>

using namespace std;
//Using Recursion + Backtracking
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

//Using Bit mask
class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> masks;
        int sub_cnt = (1<<n);

        for (int mask = 0; mask < sub_cnt; mask++)
        {
            vector<int> subset;
            for (int i = 0; i < n; i++)
            {
                if((mask & (1<<i))!=0){
                    subset.push_back(nums[i]);
                }
            }
            masks.push_back(subset);
            
        }
        
        return masks;
    }
};