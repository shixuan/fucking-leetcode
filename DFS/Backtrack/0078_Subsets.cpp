class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        dfs(nums, cur, 0);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& cur, int begin) {
        ans.push_back(cur);
        for(int i = begin; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(nums, cur, i + 1);
            cur.pop_back();
        }
    }
};