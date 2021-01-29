class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, right = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0, len = nums.size(); i < len; i++) {
            right = sum - left - nums[i];
            if(left == right)
                return i;
            left += nums[i];
        }

        return -1;
    }
};