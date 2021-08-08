class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        dfs(nums, cur, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& cur, int begin) {
        ans.push_back(cur);
        for(int i = begin; i < nums.size(); i++) {
            if(i == begin || nums[i] != nums[i - 1]) {  // 当前元素等于前一个元素说明此次递归会有重复元素加入，只在循环内判断，begin之前（上一次递归的）的元素不用考虑
                cur.push_back(nums[i]);
                dfs(nums, cur, i + 1);
                cur.pop_back();
            }
        }
    }
};