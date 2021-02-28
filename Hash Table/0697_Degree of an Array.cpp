class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, left, right;
        int degree = 0, len = nums.size();
        for(int i = 0; i < len; i++) {
            if(freq.count(nums[i]) == 0) left[nums[i]] = i;
            freq[nums[i]]++;
            right[nums[i]] = i;
            degree = max(degree, freq[nums[i]]);
        }
        
        int ans = len;
        for(auto &it : freq) {
            if(it.second == degree) {
                ans = min(ans, right[it.first] - left[it.first] + 1);
            }
        }

        return ans;
    }
};