class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Start or destination is blocked
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        if (n == 1) return 1;

        queue<pair<int,int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Distance also marks visited

        int delRow[] = {-1,-1,-1,0,0,1,1,1};
        int delCol[] = {-1,0,1,-1,1,-1,0,1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0) {

                    // First visit gives the shortest distance
                    grid[nrow][ncol] = grid[row][col] + 1;

                    if (nrow == n-1 && ncol == n-1)
                        return grid[nrow][ncol];

                    q.push({nrow, ncol});
                }
            }
        }

        return -1;
    }
};