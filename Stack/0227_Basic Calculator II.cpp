class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char preOps = '+';
        
        s.push_back('\0');  //最后一个数会操作不到，强行多补一个占位
        for(auto &ch : s) {
            if(ch == ' ') continue;
            else if(ch <= '9' && ch >= '0') {
                num = num * 10 - '0' + ch;  //先减后加，不然可能超int最大值
            }
            else {
                if(preOps == '+')   stk.push(num);
                else if(preOps == '-')  stk.push(-num);
                else if(preOps == '*') {
                    int val = stk.top();
                    stk.pop();
                    stk.push(val * num);
                }
                else if(preOps == '/') {
                    int val = stk.top();
                    stk.pop();
                    stk.push(val / num);
                }
                preOps = ch;
                num = 0;
            }
        }

        int ans = 0;
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};