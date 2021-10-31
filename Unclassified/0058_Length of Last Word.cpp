class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans = 0, i = n - 1;

        while(i >= 0 && s[i] == ' ')    i--;
        for(; i >= 0; i--) {
            if(s[i] == ' ') break;
            ans++;
        }

        return ans;
    }
};