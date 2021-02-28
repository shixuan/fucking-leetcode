class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int len = customers.size();
        int ans = 0;
        for(int i = 0; i < len; i++) {
            if(grumpy[i] == 0) ans += customers[i];
        }

        int next = 0;
        for(int i = 0; i < len; i++) {
            if(i < X) {
                ans += customers[i] * grumpy[i];
                next = ans;
            }
            else {
                next += customers[i] * grumpy[i] - customers[i - X] * grumpy[i - X];
                ans = max(ans, next);
            }
        }

        return ans;
    }
};