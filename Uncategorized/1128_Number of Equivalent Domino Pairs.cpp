class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> tb(100, 0);
        int ans = 0;
        for(auto &d : dominoes) {
            int idx = d[0] > d[1] ? d[0] * 10 + d[1] : d[1] * 10 + d[0];
            ans += tb[idx]++;
        }
        return ans;
    }
};