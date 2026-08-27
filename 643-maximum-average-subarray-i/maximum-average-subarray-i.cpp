class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0,right=k-1,n=nums.size();
        double avgSum=0,avg=INT_MIN;
        for(int i=left;i<=right;i++)  avgSum+=nums[i];
        avg=avgSum/k;
        while(right+1<n){
            left++;
            right++;
            avgSum-=nums[left-1];
            avgSum+=nums[right];
            avg=max(avg,avgSum/k);
        }
        return avg;
    }
};