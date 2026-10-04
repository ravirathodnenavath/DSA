class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image,
             int originalColor, int color) {

        int n = image.size();
        int m = image[0].size();

        // Change current pixel
        image[row][col] = color;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Visit 4 neighbours
        for (int i = 0; i < 4; i++) {

            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == originalColor) {

                dfs(nrow, ncol, image, originalColor, color);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {

        int originalColor = image[sr][sc];

        // If both colors are same, nothing needs to be changed
        if (originalColor == color)
            return image;

        dfs(sr, sc, image, originalColor, color);

        return image;
    }
};