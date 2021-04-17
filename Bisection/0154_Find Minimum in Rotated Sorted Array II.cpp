class Solution {
public:
    int findMin(vector<int>& nums) {
        int left= 0, right = nums.size() - 1;
        while(left <= right && nums[right] == nums[0])   right--;
        while(left < right) {
            int mid = (left + right) - 1;
            if(nums[mid] > nums[right]) left = mid + 1;
            else    right = mid;
        }

        return nums[left];
    }
};