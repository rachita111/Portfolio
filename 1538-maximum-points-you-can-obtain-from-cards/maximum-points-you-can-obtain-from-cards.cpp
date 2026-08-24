class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftS=0,rightS=0,rightI=n-1,maxS=0;
        for(int i=0;i<k;i++) leftS+=cardPoints[i];
        maxS=leftS;
        for(int i=k-1;i>=0;i--){
            leftS-=cardPoints[i];
            rightS+=cardPoints[rightI];
            rightI--;
            maxS=max(maxS,leftS+rightS);
        }
        return maxS;
    }
};