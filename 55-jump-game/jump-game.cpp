class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minInd=0;
        for(int i=0;i<nums.size();i++){
            if(i>minInd) return false;
            minInd=max(minInd,i+nums[i]);
        }
        return true;
    }
};