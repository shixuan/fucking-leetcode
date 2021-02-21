class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int originR = nums.size(), originC = nums[0].size();
        if(originR * originC != r * c) return nums;

        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i < originR * originC; i++) {
            ans[i / c][i % c] = nums[i / originC][i % originC];
        }

        return ans;
    }
};