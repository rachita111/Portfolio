class Solution {
public:
    string reverseStr(string &s,int start,int end){
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
        return s;
    }
    string reverseWords(string s) {
        int start=0,end=0,n=s.length();
        while(start<n && end<n){
            if(start!=0){
                while(start<n && s[start]==' ') start++;
            }
            end=start;
            while(end<n && s[end]!=' ' ) end++;
            reverseStr(s,start,end-1);
            start=end;
        }
        return s;
    }
};