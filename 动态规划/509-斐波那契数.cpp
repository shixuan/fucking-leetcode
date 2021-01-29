class Solution {
public:
    int fib(int n) {
        if(n < 2) return n;
        vector<int> fibbo(n + 1, 0);
        fibbo[0] = 0;
        fibbo[1] = 1;
        for(int i = 2; i <= n; i++) {
            fibbo[i] = fibbo[i - 1] + fibbo[i - 2];
        }

        return fibbo[n];
    }
};