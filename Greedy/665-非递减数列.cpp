class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i = 0, len = nums.size(); i < len - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                count++;
                if(i > 0 && nums[i - 1] > nums[i + 1])  //左边大于右边，需要把右边变大
                    nums[i + 1] = nums[i];
                else    //左边小于右边或者没有左边，当前的变小
                    nums[i] = nums[i + 1];
            }
        }
        return count <= 1;
    }
};