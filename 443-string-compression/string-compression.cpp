class Solution {
public:
    int compress(vector<char>& chars) {
        int start=0,end=0,i=0,n=chars.size();
        while(end<n){
            while(end<n && chars[end]==chars[start]) end++;
            chars[i]=chars[start];
            i++;
            if(end-start>1){
                string cnt=to_string(end-start);
                for(char c:cnt){
                    chars[i]=c;
                    i++;
                }
            }
            start=end;
        }
        return i;
    }
};