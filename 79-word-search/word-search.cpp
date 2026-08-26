class Solution {
public:
    bool helper(int ind,int row,int col,vector<vector<char>>& board, string word){
        int n=board.size(),m=board[0].size();
        char marked=board[row][col];
        if(marked!=word[ind]) return false;
        else board[row][col]='#';
        if(ind==word.size()-1){
            // board[row][col]=marked;
            return true;
        }
        if(row!=0 && board[row-1][col]!='#'){
            if(helper(ind+1,row-1,col,board,word)==true){
                // board[row][col]=marked;
                return true;
            }
        }
        if(row+1!=n && board[row+1][col]!='#'){
            if(helper(ind+1,row+1,col,board,word)==true){
                // board[row][col]=marked;
                return true;
            }
        }
        if(col!=0 && board[row][col-1]!='#'){
            if(helper(ind+1,row,col-1,board,word)==true){
                // board[row][col]=marked;
                return true;
            }
        }
        if(col+1!=m && board[row][col+1]!='#'){
            if(helper(ind+1,row,col+1,board,word)==true){
                board[row][col]=marked;
                return true;
            }
        }
        board[row][col]=marked;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(helper(0,i,j,board,word)) return true;
            }
        }
        return false;
    }
};