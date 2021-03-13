class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int sign = 1;
        stack<int> stk;
        stk.push(sign);

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ' ')   continue;
            else if(s[i] == '+') 
                sign = stk.top();
            else if(s[i] == '-')
                sign = -stk.top();
            else if(s[i] == '(')
                stk.push(sign);
            else if(s[i] == ')') 
                stk.pop();
            else {
                long long num = 0;
                for( ;i < s.size() && s[i] >= '0' && s[i] <= '9'; i++)
                    num = num * 10 + s[i] - '0';
                ans += num * sign;
                i--;
            }
        }

        return ans;
    }
};