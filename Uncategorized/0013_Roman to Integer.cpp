class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> tb = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans = 0, pre = tb[s[0]];
        for(int i = 1; i < s.size(); i++) {
            int val = tb[s[i]];
            if(pre < val)
                ans -= pre;
            else
                ans += pre;
            pre = val;
        }
        ans += pre;

        return ans;
    }
};