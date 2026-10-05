class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int enclaves = 0;

        queue<pair<int, int>> q;

        // Put all boundary land cells into the queue
        for (int i = 0; i < n; i++) {

            if (grid[i][0] == 1) {
                grid[i][0] = 2;
                q.push({i, 0});
            }

            if (grid[i][m - 1] == 1) {
                grid[i][m - 1] = 2;
                q.push({i, m - 1});
            }
        }

        for (int i = 0; i < m; i++) {

            if (grid[0][i] == 1) {
                grid[0][i] = 2;
                q.push({0, i});
            }

            if (grid[n - 1][i] == 1) {
                grid[n - 1][i] = 2;
                q.push({n - 1, i});
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {

                int nextrow = row + delRow[i];
                int nextcol = col + delCol[i];

                // Check valid cell and boundary-connected land
                if (nextrow >= 0 && nextrow < n &&
                    nextcol >= 0 && nextcol < m &&
                    grid[nextrow][nextcol] == 1) {

                    grid[nextrow][nextcol] = 2;
                    q.push({nextrow, nextcol});
                }
            }
        }

        // Remaining 1's are enclaves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    enclaves++;
                }
                else if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }

        return enclaves;
    }
};