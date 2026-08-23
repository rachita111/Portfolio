class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, -1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']=i;
            if(freq[0]!=-1 && freq[1]!=-1 && freq[2]!=-1){
                ans+=(1+min(freq[0],min(freq[1],freq[2])));
            }
        }
        return ans;
    }
};