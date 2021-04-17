class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];
        vector<int> dp1(n + 1); // dp1抢第一个不抢最后一个
        vector<int> dp2(n + 1); // dp2不抢第一个抢最后一个
        dp1[0] = 0;
        dp1[1] = nums[0];
        dp2[0] = 0;
        dp2[0] = 0;
        for(int i = 2; i <= n; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
        }
        
        return max(dp1[n - 1], dp2[n]);
    }
};