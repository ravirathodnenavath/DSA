class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Multi-source BFS: all initially rotten oranges start at time 0
        queue<pair<pair<int, int>, int>> q;

        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;
        int rotten = 0;

        // Directions: up, right, down, left
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();

            time = max(time, t);

            for (int i = 0; i < 4; i++) {

                int nrow = r + delr[i];
                int ncol = c + delc[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1) {

                    // Mark immediately to prevent visiting the same orange again
                    grid[nrow][ncol] = 2;

                    q.push({{nrow, ncol}, t + 1});

                    rotten++;
                }
            }
        }

        // Some fresh oranges could not be reached
        if (fresh != rotten) {
            return -1;
        }

        return time;
    }
};