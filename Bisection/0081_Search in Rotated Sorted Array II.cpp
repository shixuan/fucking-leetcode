class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums[0] == target) return true;
        int left = 0, right = nums.size() - 1;
        while(left < right && nums[right] == nums[0]) right--;
        int n = right;

        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[mid] >= nums[0])   left = mid + 1;
            else right = mid - 1;
        }

        if(target > nums[0]) left = 1;
        else    right = n;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) return true;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        return false;
    }
};