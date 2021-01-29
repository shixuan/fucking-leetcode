class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int start = 0, ans = 0;
        int len = nums.size();

        for(int i = 0; i < len; i++) {
            if(i > 0 && nums[i] <= nums[i - 1]) {
                start = i;
            }
            else {
                ans = max(i - start + 1, ans);
            }
        }

        return ans;
    }
};