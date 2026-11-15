class Solution {
public:
    bool comparator(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),
            [this](auto& a,auto& b){
            return comparator(a,b);
        });
        int end=INT_MIN,cnt=0,n=intervals.size();
        for(int i=0;i<n;i++){
            if(end<=intervals[i][0]){
                cnt++;
                end=intervals[i][1];
            }
        }
        return n-cnt;
    }
};