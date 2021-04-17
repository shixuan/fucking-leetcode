class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums[0] == target) return 0;
        int left = 0, right = nums.size() - 1;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] >= nums[left]) { //左半边     mid与left比，需加等号，与right比则不需。因为向下取整mid可能等于left。
                if(nums[mid] > target && target >= nums[left])  right = mid - 1;
                else    left = mid + 1;
            }
            else {  //右半边
                if(nums[mid] < target && target <= nums[right])  left = mid + 1;
                else    right = mid - 1;
            }
        }

        return -1;
    }
};