class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
 
        queue<pair<int, int>> q;
 
        vector<int> deltaRow = {-1, 1, 0, 0};
        vector<int> deltaCol = {0, 0, -1, 1};
 
        // Add land cells from the left and right boundaries.
        for (int row = 0; row < rows; row++) {
            for (int col : {0, cols - 1}) {
                // If boundary cell is land, mark and push it.
                if (grid[row][col] == 1) {
                    grid[row][col] = 0;
                    q.push({row, col});
                }
            }
        }
 
        // Add land cells from the top and bottom boundaries.
        for (int col = 0; col < cols; col++) {
            for (int row : {0, rows - 1}) {
                // If boundary cell is land, mark and push it.
                if (grid[row][col] == 1) {
                    grid[row][col] = 0;
                    q.push({row, col});
                }
            }
        }
 
        // Remove all land connected to boundary land cells.
        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
 
            // Explore all four adjacent directions.
            for (int dir = 0; dir < 4; dir++) {
                int nextRow = cell.first + deltaRow[dir];
                int nextCol = cell.second + deltaCol[dir];
 
                // Check if the next cell is inside the grid.
                if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                    // If connected cell is land, mark and push it.
                    if (grid[nextRow][nextCol] == 1) {
                        grid[nextRow][nextCol] = 0;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }
 
        int enclaves = 0;
 
        // Count the remaining land cells.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                enclaves += grid[row][col];
            }
        }
 
        // Return the number of enclave cells.
        return enclaves;
    }
};