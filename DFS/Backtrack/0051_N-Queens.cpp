class Solution {
public:
    vector<vector<string>> ans;

    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n);
        unordered_map<int, int> diagL(2 * n - 1); // see 0052
        unordered_map<int, int> diagR(2 * n - 1);
        vector<int> path(n);                      // path[i] = j means there is a queen at [i, j]
        dfs(0, n, path, col, diagL, diagR);

        return ans;
    }

    void dfs(int row, int n, vector<int>& path,
            vector<int>& col, unordered_map<int, int>& diagL, unordered_map<int, int>& diagR) {
        if (row > n - 1) {
            ans.push_back(std::move(newBoard(path, n)));
            return;
        }

        for (int i = 0; i < n; i++) {
            if(col[i] || diagL[row + i] || diagR[row - i])
                continue;
            col[i] = 1;
            diagL[row + i] = 1;
            diagR[row - i] = 1;
            path[row] = i;
            dfs(row + 1, n, path, col, diagL, diagR);
            col[i] = 0;
            diagL[row + i] = 0;
            diagR[row - i] = 0;
            path[row] = 0;
        }
    }

    vector<string> newBoard(vector<int>& path, int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string line(n, '.');
            line[path[i]] = 'Q';
            board.push_back(std::move(line));
        }
        return board;
    }
};