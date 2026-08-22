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
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1) nums[i]=1;
            else if(nums[i]%2==0) nums[i]=0;
        }
        return numSubarraysWithSum(nums,k);
    }
};


// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int right=0,left=0,cnt=0,ans=0,evenC=0;
//         while(right<nums.size()){
//             if(nums[right]%2==1){
//                 cnt++;
//                 right++;
//             }else if(nums[right]%2==0){
//                 if(cnt==0) evenC++;
//                 right++;
//             }
//             if(cnt==k) ans++;
//             else if(cnt>k){
//                 left++;
//                 if(nums[left]%2==1) cnt--;
//             }
//         }
//         return ans;
//     }
// };