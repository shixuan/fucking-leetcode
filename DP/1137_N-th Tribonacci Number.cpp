class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)  return 0;
        if(n == 1 || n == 2)    return 1;

        int a = 0, b = 0, c = 1, ans = 1;
        
        for(int i = 3; i <= n; i++) {
            a = b;
            b = c;
            c = ans;
            ans = a + b + c;
        }
        
        return ans;
    }
};