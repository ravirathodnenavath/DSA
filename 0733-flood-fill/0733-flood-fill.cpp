class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int oldColor = image[sr][sc];
 
        // If the new color is the same, no change is needed.
        if (oldColor == color) {
            return image;
        }
 
        vector<int> deltaRow = {-1, 1, 0, 0};
        vector<int> deltaCol = {0, 0, -1, 1};
        queue<pair<int, int>> q;
 
        // Recolor the starting cell.
        image[sr][sc] = color;
 
        // Push the starting cell into the queue.
        q.push({sr, sc});
 
        // Recolor all connected cells having the original color.
        while (!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();
 
            // Explore all four adjacent directions.
            for (int dir = 0; dir < 4; dir++) {
                int nextRow = cell.first + deltaRow[dir];
                int nextCol = cell.second + deltaCol[dir];
 
                // Check if the next cell is inside the image.
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols) {
                    // Recolor only cells that have the old color.
                    if (image[nextRow][nextCol] == oldColor) {
                        image[nextRow][nextCol] = color;
                        q.push({nextRow, nextCol});
                    }
                }
            }
        }
 
        // Return the updated image.
        return image;
    }
};