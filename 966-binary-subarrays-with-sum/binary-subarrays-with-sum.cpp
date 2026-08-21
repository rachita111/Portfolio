class Solution {
public:
    int goalCnt(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int right=0,left=0,cnt=0;
        long long sum=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            cnt+=(right-left+1);
            right++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (goalCnt(nums,goal)-goalCnt(nums,goal-1));
    }
};