class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0, len = nums.size(); i < len; i += 2) {
            ans += nums[i];
        }

        return ans;
    }
};