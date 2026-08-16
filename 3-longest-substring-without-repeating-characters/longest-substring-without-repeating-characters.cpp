class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,len=0,maxLen=0,n=s.length();
        vector<int> mpp(256,-1);
        while(n>right){
            if(mpp[s[right]]!=-1){
                if(mpp[s[right]]>=left) left=mpp[s[right]]+1;
            }
            len=right-left+1;
            maxLen=max(maxLen,len);
            mpp[s[right]]=right;
            right++;
        }
        return maxLen;
    }
};