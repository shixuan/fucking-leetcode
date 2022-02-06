class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibo;
        genFibo(fibo, k);   // generate the fibo list lesser than k
        int idx = fibo.size() - 1;
        int ans = 0;
        while (k) {
            if (fibo[idx] <= k) {   // it's impossible to use a fibo num more than once
                k -= fibo[idx];
                ans++;
            }
            idx--;
        }
        return ans;
    }

    void genFibo(vector<int>& fibo, int k) {
        int a = 1, b = 1, tmp = 0;
        fibo.push_back(1);
        while (b <= k) {
            tmp = b;
            b = a + b;
            a = tmp;
            if (b <= k)
                fibo.push_back(b);
        }
    }
};