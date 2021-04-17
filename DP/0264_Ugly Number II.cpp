class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for(int p2 = 1, p3 = 1, p5 = 1, i = 2; i <= n; i++) {
            int a = dp[p2] * 2, b = dp[p3] * 3, c = dp[p5] * 5;
            dp[i] = min(a, min(b, c));
            if(dp[i] == a)  p2++;
            if(dp[i] == b)  p3++;
            if(dp[i] == c)  p5++;
        }

        return dp[n];
    }
};