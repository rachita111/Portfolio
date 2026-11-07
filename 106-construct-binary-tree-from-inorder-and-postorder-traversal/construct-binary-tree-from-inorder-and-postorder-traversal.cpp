class Solution {
public:
    TreeNode* buildTreePostIn(vector<int>& inorder,int is,int ie,vector<int>& postorder,int ps,int pe,map<int,int>& inMap){
        if(ps>pe || is>ie) return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inRoot=inMap[root->val];
        int numsLeft=inRoot-is;
        root->left=buildTreePostIn(inorder,is,inRoot-1,postorder,ps,ps-1+numsLeft,inMap);
        root->right=buildTreePostIn(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,inMap);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        return buildTreePostIn(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);
    }
};