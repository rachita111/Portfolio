class Solution {
public:
    int helper(TreeNode* root,int& maxS){
        if(root==NULL) return 0;
        int left=max(0,helper(root->left,maxS));
        int right=max(0,helper(root->right,maxS));
        maxS=max(maxS,root->val+right+left);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxS=INT_MIN;
        helper(root,maxS);
        return maxS;
    }
};