class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();  // right=size-1的话循环条件为left<=right; left=mid+1, right=mid-1;
        int mid = 0;
        while(left < right) {
            mid = (left + right) / 2;
            if(nums[mid] == target) return mid;

            if(nums[mid] > target)  right = mid ;
            else if(nums[mid] < target) left = mid + 1;
        }

        return -1;
    }
};