class Solution {
public:
    int minCut(string s) {
        int len = s.size();

        vector<vector<int>> pali(len, vector<int>(len, true));
        for(int i = len - 1; i >= 0; i--) { //判断子字符串s[i, j]是否回文
            for(int j = i + 1; j < len; j++) {
                pali[i][j] = pali[i + 1][j - 1] & (s[i] == s[j]);
            }
        }

        vector<int> f(len, len);
        for(int i = 0; i < len; i++) {
            if(pali[0][i]) {
                f[i] = 0;
                continue;
            }

            for(int j = 0; j < i; j++) {
                if(pali[j + 1][i])
                    f[i] = min(f[i], f[j] + 1);
            }
        }

        return f[len - 1];
    }
};