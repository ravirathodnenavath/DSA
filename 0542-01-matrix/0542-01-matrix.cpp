class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>> q;

        // Distance array: -1 means not visited
        vector<vector<int>> dist(n, vector<int>(m, -1));

        // Put all 0s into queue first
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // 4 directions
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {

                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    dist[nrow][ncol] == -1) {

                    // First time we reach a cell = shortest distance
                    dist[nrow][ncol] = dist[r][c] + 1;

                    q.push({nrow, ncol});
                }
            }
        }

        return dist;
    }
};