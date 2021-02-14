/*
    1.原地哈希
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++) {
            while(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }

        vector<int> ans;
        for(int i = 0; i < len; i++) {
            if(nums[i] != i + 1)
                ans.push_back(i + 1);
        }

        return ans;
    }
};

/*
    2. 下标变负
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len; i++)
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);

        vector<int> ans;
        for(int i = 0; i < len; i++) {
            if(nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};