class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> s;
        unordered_map<int, int> nge;
        
        for(auto ele : nums2){
         
            while(!s.empty() && s.top()<ele){
                                     
                int t = s.top();
                nge[t] = ele; 
                s.pop();
         }
            s.push(ele);
            
        }
        vector<int> ans;
        // return {nums2[NGE[nums1[1]]]};
        // for(int i= 0 ; i<nums1.size();i++){
        //     if(NGE[nums1[i]]==-1){
        //         ans[i] = -1;
        //     }else{
        //     ans[i] = nums2[NGE[nums1[i]]];
        //     }
        // }
        
        for(auto ele : nums1){
            ans.push_back(nge.count(ele)?nge[ele]:-1);
            
        }
       return ans;
    }
};