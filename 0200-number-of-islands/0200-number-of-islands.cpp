class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {

        int n = grid.size();
        int m = grid[0].size();

        // Mark starting cell as visited
        visited[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        // 4 directions: up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Check all 4 neighbours
            for (int i = 0; i < 4; i++) {

                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' &&
                    !visited[nrow][ncol]) {

                    // Mark before pushing to avoid duplicate visits
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                // Every unvisited land starts a new island
                if (!visited[row][col] && grid[row][col] == '1') {

                    cnt++;
                    bfs(row, col, grid, visited);
                }
            }
        }

        return cnt;
    }
};