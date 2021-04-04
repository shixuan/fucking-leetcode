class Solution {
public:
    int clumsy(int N) {
        stack<int> stk;
        int count = 1;
        stk.push(N);
        for(int i = N - 1; i > 0; i--) {
            if(count % 4 == 0)  stk.push(-i);
            else if(count % 4 == 1) {
                int val = stk.top();
                stk.pop();
                stk.push(val * i);
            }
            else if(count % 4 == 2) {
                int val = stk.top();
                stk.pop();
                stk.push(val / i);
            }
            else stk.push(i);
            count++;
        }

        int ans = 0;
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};