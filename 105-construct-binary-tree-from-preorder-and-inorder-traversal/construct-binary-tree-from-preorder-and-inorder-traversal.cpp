class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder,int preStrt,int preEnd,vector<int>& inorder,int inStrt,int inEnd,map<int,int>& inMap){
        if(preStrt>preEnd || inStrt>inEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStrt]);
        int inRoot=inMap[root->val];
        int numsLeft=inRoot-inStrt;
        root->left=buildTree(preorder,preStrt+1,preStrt+numsLeft,inorder,inStrt,inRoot,inMap);
        root->right=buildTree(preorder,preStrt+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }
};