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
    void helper(TreeNode* root,vector<TreeNode*>& ans){
        if(root==NULL) return;
        ans.push_back(root);
        helper(root->left,ans);
        helper(root->right,ans);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        helper(root,ans);
        for(int i=1;i<ans.size();i++){
            root->right=ans[i];
            root->left=NULL;
            root=root->right;
        }
    }
};