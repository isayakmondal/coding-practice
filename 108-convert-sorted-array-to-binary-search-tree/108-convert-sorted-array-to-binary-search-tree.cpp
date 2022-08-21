/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    TreeNode* func(int s, int e, vector<int>& nums){
        
        if(s>e || s>nums.size()-1 || e<0) return nullptr;
        
        int mid = (s+e)/2;
        TreeNode *root = new TreeNode();
        root->val=nums[mid];
        root->left=func(s,mid-1,nums);
        root->right=func(mid+1,e,nums);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return func(0,nums.size()-1,nums);
    }
};