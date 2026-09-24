class Solution {
public:
    // Function to find minimum minutes using multi-source BFS.
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        int minutes = 0;
        queue<pair<int, int>> q;

        // Collect all rotten oranges as BFS sources.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] == 2) {
                    q.push({row, col});
                } else if (grid[row][col] == 1) {
                    fresh++;
                }
            }
        }

        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};

        // Process BFS level by level while fresh oranges remain.
        while (!q.empty() && fresh > 0) {
            int levelSize = q.size();

            // Process all oranges rotting during current minute.
            for (int count = 0; count < levelSize; count++) {
                auto [row, col] = q.front();
                q.pop();

                // Spread rot to adjacent fresh oranges.
                for (int dir = 0; dir < 4; dir++) {
                    int nextRow = row + dRow[dir];
                    int nextCol = col + dCol[dir];

                    if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols && grid[nextRow][nextCol] == 1) {
                        grid[nextRow][nextCol] = 2;
                        fresh--;
                        q.push({nextRow, nextCol});
                    }
                }
            }

            minutes++;
        }

        // Return -1 when unreachable fresh oranges remain.
        if (fresh > 0) {
            return -1;
        }

        // Return minimum elapsed minutes.
        return minutes;
    }
};        