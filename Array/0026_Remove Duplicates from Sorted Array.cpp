class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int i, j;
        for(i = 1, j = 0; i < nums.size(); i++) {
            if(nums[j] != nums[i])
                nums[++j] = nums[i];
        }

        return ++j;
    }
};