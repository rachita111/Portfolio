class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        int ans=n;
        unordered_map<char,pair<int,int>> mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]].first++;
            mpp[s[i]].second=i;
        }
        for(auto ch:mpp){
            if(ch.second.first==1) ans=min(ans,ch.second.second);
        }
        return ans==n?-1:ans;
    }
};