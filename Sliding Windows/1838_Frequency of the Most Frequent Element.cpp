class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = 1;
        int left = 0, right = 1;
        long long sum = 0;
        while(right < nums.size()) {
            sum += (long long)(nums[right] - nums[right - 1]) * (right - left);
            while(sum > k) {
                sum -= nums[right] - nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};