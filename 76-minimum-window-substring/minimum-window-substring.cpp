class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";
        int n=s.size(),m=t.size(),minL=INT_MAX,sInd=-1,right=0,left=0,cnt=0;  
        unordered_map<char,int> mpp; 
        for(int j=0;j<m;j++) mpp[t[j]]++;
        while(right<n){
            if(mpp[s[right]]>0) cnt++;
            mpp[s[right]]--;
            while(left<n && cnt==m){
                if(minL>right-left+1){
                    minL=right-left+1;
                    sInd=left;
                }
                if(mpp[s[left]]>=0) cnt--;
                mpp[s[left]]++;
                left++;
            }
            right++;
        }
        return sInd==-1?"":s.substr(sInd,minL);
    }
};