class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool>(n));    //第i块石头是否可以通过跳k个石头跳过来
        dp[0][0] = true;

        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                int k = stones[i] - stones[j];
                // 上一步最大是从0跳到j，步长为j，所以此次步长最大为j+1
                if(k > j + 1) break;

                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if(dp[n - 1][k]) return true;
            }
        }

        return false;
    }
};