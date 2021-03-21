class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));

        int upper = 0, bottom = n - 1, left = 0, right = n - 1;
        int count = 0;
        
        while(1) {
            for(int i = left; i <= right; i++) ans[upper][i] = ++count;
            if(++upper > bottom) break;
            for(int i = upper; i <= bottom; i++) ans[i][right] = ++count;
            if(--right < left) break;
            for(int i = right; i >= left; i--) ans[bottom][i] = ++count;
            if(--bottom < upper) break;
            for(int i = bottom; i >= upper; i--) ans[i][left] = ++count;
            if(++left > right) break;
        }

        return ans;
    }
};