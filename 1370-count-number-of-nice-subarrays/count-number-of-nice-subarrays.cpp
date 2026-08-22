class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int right = 0, left = 0;
        int cnt = 0, ans = 0;

        while (right < nums.size()) {

            if (nums[right] % 2 == 1) {
                cnt++;
            }

            while (cnt > k) {
                if (nums[left] % 2 == 1) {
                    cnt--;
                }
                left++;
            }

            if (cnt == k) {
                int temp = left;

                // Count how many even elements
                // can be removed from the left
                while (temp < nums.size() && nums[temp] % 2 == 0) {
                    temp++;
                }

                ans += temp - left + 1;
            }

            right++;
        }

        return ans;
    }
};