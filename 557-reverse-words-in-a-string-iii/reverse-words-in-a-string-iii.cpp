class Solution {
public:
    string reverseWords(string s) {
        int start=0,end=0,n=s.length();
        while(start<n){
            while(start<n && s[start]==' ') start++;
            end=start;
            while(end<n && s[end]!=' ' ) end++;
            reverse(s.begin()+start,s.begin()+end);
            start=end;
        }
        return s;
    }
};