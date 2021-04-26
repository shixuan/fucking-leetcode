class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n), path(n);

        for(int i = 0; i < n; i++) {
            int len = 1, prev = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > len) {
                    len = dp[j] + 1;
                    prev = j;
                }
            }
            path[i] = prev;
            dp[i] = len;
        }

        int idx = max_element(dp.begin(), dp.end()) - dp.begin();
        int len = dp[idx];

        vector<int> ans;
        for(int i = 0; i < len; i++) {
            ans.push_back(nums[idx]);
            idx = path[idx];
        }

        return ans;
    }
};