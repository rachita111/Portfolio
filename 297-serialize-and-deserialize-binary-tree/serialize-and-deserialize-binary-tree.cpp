class Codec {
public:
    string serialize(TreeNode* root) {
        string ans="";
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root); 
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL) ans.append("N,");
            else ans.append(to_string(curr->val)+',');
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
    }
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="N") node->left=NULL;
            else{
                TreeNode* leftNode=new TreeNode (stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="N") node->right=NULL;
            else{
                TreeNode* rightNode=new TreeNode (stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        } 
        return root;
    }
};