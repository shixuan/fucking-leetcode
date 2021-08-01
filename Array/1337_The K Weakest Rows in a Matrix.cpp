class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> val(mat.size());
        for(int i = 0; i < mat.size(); i++) {
            val[i] = accumulate(mat[i].begin(), mat[i].end(), 0) * 100 + i;
        }

        sort(val.begin(), val.end());
        vector<int> ans(k);
        for(int i = 0; i < k; i++) {
            ans[i] = val[i] % 100;
        }

        return ans;
    }
};