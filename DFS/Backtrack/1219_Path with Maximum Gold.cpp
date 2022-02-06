class Solution {
public:
    int ans = 0;

    int getMaximumGold(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (0 == grid[i][j])
                    continue;
                dfs(grid, i, j, 0);
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int cur) {
        if (0 == grid[row][col])
            return;
        int tmp = grid[row][col];
        cur += tmp;
        grid[row][col] = 0;
        ans = max(ans, cur);
        if (row > 0)
            dfs(grid, row - 1, col, cur);
        if (row < grid.size() - 1)
            dfs(grid, row + 1, col, cur);
        if (col > 0)
            dfs(grid, row, col - 1, cur);
        if (col < grid[0].size() - 1)
            dfs(grid, row, col + 1, cur);
        // cur -= tmp;  // no difference. cur is passed by value. it will not affect last or next recursion.
        grid[row][col] = tmp;
    }
};