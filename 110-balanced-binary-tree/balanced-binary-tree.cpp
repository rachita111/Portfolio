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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        int val=abs(lh-rh);
        bool rr=isBalanced(root->right);
        bool lr=isBalanced(root->left); 
        if(val<=1 && lr==true && rr==true) return true;
        return false;
    }
};