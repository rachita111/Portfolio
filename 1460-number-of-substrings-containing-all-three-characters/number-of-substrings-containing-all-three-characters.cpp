class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1,right=0,ans=0;
        while(right<s.size()){
            if(s[right]=='a') a=right;
            else if(s[right]=='b') b=right;
            else c=right;
            if(a>=0 && b>=0 && c>=0){
                int cnt=min(a,min(b,c));
                ans+=cnt+1;
            }
            right++;
        }
        return ans;
    }
};