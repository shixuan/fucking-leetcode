class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, right = 0, len = nums.size();
        multiset<int> set;
        while(right < len) {
            set.insert(nums[right]);
            if((*set.rbegin() - *set.begin()) > limit) {
                set.erase(set.find(nums[left]));
                left++;
            }
            right++;
        }

        return right - left;
    }
};