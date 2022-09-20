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
    
    static const int n = 1e3+10;
    bool vis[n];
    vector<int> ans;
    
    void helper(TreeNode *root, int level){
        
        if(root==NULL) return;
        
        if(!vis[level]){
            ans.push_back(root->val);
            vis[level]=true;
        }
        
        helper(root->right,level+1);
        helper(root->left,level+1);
        
    
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        helper(root,0);
        return ans;
    }
};