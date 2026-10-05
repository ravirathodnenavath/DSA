class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        grid[row][col] = 2;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {

            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1) {

                dfs(nrow, ncol, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Start DFS from all boundary 1s
        for (int i = 0; i < n; i++) {

            if (grid[i][0] == 1)
                dfs(i, 0, grid);

            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid);
        }

        for (int j = 0; j < m; j++) {

            if (grid[0][j] == 1)
                dfs(0, j, grid);

            if (grid[n - 1][j] == 1)
                dfs(n - 1, j, grid);
        }

        int enclaves = 0;

        // Remaining 1s cannot reach the boundary
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1)
                    enclaves++;
            }
        }

        return enclaves;
    }
};