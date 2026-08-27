class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxL=0,right=0,cnt=0;
        while(right<nums.size()){
            if(nums[right]==1){
                cnt++;
                maxL=max(maxL,cnt);
            }else cnt=0;
            right++;
        }
        return maxL;
    }
};