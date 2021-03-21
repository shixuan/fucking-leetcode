class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto &str : tokens) {
            if((str[0] >= '0' && str[0] <= '9') || (str[0] == '-' && str[1] >= '0' && str[1] <= '9')) {
                int num = 0;
                for(auto &ch : str) {
                    if(ch == '-')    continue;
                    num = num * 10 + ch - '0';
                }
                if(str[0] == '-')   num *= -1;
                stk.push(num);
            }
            else {
                int val1 = stk.top();
                stk.pop();
                int val2 = stk.top();
                stk.pop();
                if(str[0] == '+')   stk.push(val1 + val2);
                else if(str[0] == '-')  stk.push(val2 - val1);
                else if(str[0] == '*')  stk.push(val1 * val2);
                else if(str[0] == '/')  stk.push(val2 / val1);
            }
        }

        return stk.top();
    }
};