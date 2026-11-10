class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int right=0,left=0;
        while(left<s.size() && right<g.size()){
            if(g[right]<=s[left]) {
                right++;
                left++;
            }
            else left++;
        }
        return right;
    }
};