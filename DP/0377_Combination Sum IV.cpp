class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        
        for(int i = 1; i <= target; i++) {
            for(int n : nums) {
                if(i >= n) dp[i] = (0LL + dp[i] + dp[i - n]) % INT_MAX; //防止中间项溢出
            }
        }

        return dp[target];
    }
};