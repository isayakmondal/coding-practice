class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<k;i++){
            
            while(!q.empty() && nums[i]>q.front()){
                q.pop_front();
            }
            while(!q.empty() && nums[i]>q.back()){
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        ans.push_back(q.front());
        
        for(int j=k;j<nums.size();j++){
            
            if(nums[j-k]==q.front()){
                q.pop_front();
            }
            while(!q.empty() && nums[j]>q.front()){
                q.pop_front();
            }
            while(!q.empty() && nums[j]>q.back()){
                q.pop_back();
            }
            q.push_back(nums[j]);
            ans.push_back(q.front());
        }
        
        return ans;
    }
};