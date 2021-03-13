class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> f(len, 1);
        int ans = 1;
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j])
                    f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
        }

        return ans;
    }
};