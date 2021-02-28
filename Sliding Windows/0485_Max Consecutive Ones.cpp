class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int ans = 0, left = 0, right = 0;
        while(right < len) {
            if(nums[right]) {
                 right++;
            }
            else {
                ans = max(ans, right - left);
                right++;
                left = right;
            }
        }

        return max(ans, right - left);;
    }
};