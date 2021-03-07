class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int len = envelopes.size();
        if(len == 0) return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> f(len);
        int ans = 1;
        for (int i = 0; i < len; i++) {
            f[i] = 1; 
            for (int j = i - 1; j >= 0; j--) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }

            ans = max(ans, f[i]);
        }
        return ans;
    }
};