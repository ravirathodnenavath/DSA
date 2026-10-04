class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        // Put all boundary O's into the queue
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '#';
            }

            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                board[i][m - 1] = '#';
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = '#';
            }

            if (board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                board[n - 1][j] = '#';
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Find all O's connected to the boundary
        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {

                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    board[nrow][ncol] == 'O') {

                    board[nrow][ncol] = '#';
                    q.push({nrow, ncol});
                }
            }
        }

        // Remaining O's are surrounded
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};