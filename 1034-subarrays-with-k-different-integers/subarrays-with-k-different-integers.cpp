class Solution {
public:
    int helper(vector<int>& nums, int k){
        int n=nums.size(),right=0,left=0,cnt=0;
        unordered_map<int,int> mpp;
        while(right<n){
            mpp[nums[right]]++;
            while(left<n && mpp.size()>k){
                    mpp[nums[left]]--;
                    if(mpp[nums[left]]==0) mpp.erase(nums[left]);
                    left++;
                }
            if(mpp.size()<=k){
                // int temp=left;
                // while(temp<n && mpp.size()==k){
                //     mpp[nums[temp]]--;
                //     temp++; 
                // }
                // if(left>0) left--;
                cnt+=(right-left+1);
            }
            right++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};