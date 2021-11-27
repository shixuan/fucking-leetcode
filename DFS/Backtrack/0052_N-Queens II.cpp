class Solution {
public:
    int cnt = 0;

    int totalNQueens(int n) {
        vector<int> col(n);                         // is occupied or not for a col
        unordered_map<int, int> diagL(2 * n - 1);   // is occupied or not for a left diagonal.
                                                    // For each left diagonal, (row+col) are the same.
        unordered_map<int, int> diagR(2 * n - 1);   // is occupied or not for a right diagonal.
                                                    // For each left diagonal, (row-col) are the same.
        dfs(0, n, col, diagL, diagR);
        return cnt;
    }

    void dfs(int row, int n, vector<int>& col, unordered_map<int, int>& diagL, unordered_map<int, int>& diagR) {
        if (row > n - 1) {
            cnt++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if(col[i] || diagL[row + i] || diagR[row - i])
                continue;
            col[i] = 1;
            diagL[row + i] = 1;
            diagR[row - i] = 1;
            dfs(row + 1, n, col, diagL, diagR);
            col[i] = 0;
            diagL[row + i] = 0;
            diagR[row - i] = 0;
        }
    }
};