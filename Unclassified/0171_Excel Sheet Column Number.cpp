class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        int len = columnTitle.size();
        for(int i = 0; i < len; i++)
            ans = ans * 26 + (columnTitle[i] - 64);

        return ans;
    }
};