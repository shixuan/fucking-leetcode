class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;

        int upper = 0, bottom = m - 1, left = 0, right = n - 1;
        
        while(1) {
            for(int i = left; i <= right; i++) ans.push_back(matrix[upper][i]);
            if(++upper > bottom) break;
            for(int i = upper; i <= bottom; i++) ans.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
            if(--bottom < upper) break;
            for(int i = bottom; i >= upper; i--) ans.push_back(matrix[i][left]);
            if(++left > right) break;
        }

        return ans;
    }
};