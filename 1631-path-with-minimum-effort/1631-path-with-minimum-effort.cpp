class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // {effort, row, col}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [effort, row, col] = pq.top();
            pq.pop();

            // Ignore outdated entries
            if (effort > dist[row][col])
                continue;

            if (row == n - 1 && col == m - 1)
                return effort;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m) {

                    int diff = abs(heights[nrow][ncol] -
                                   heights[row][col]);

                    // Path effort is the maximum edge difference
                    int newEffort = max(effort, diff);

                    if (newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, nrow, ncol});
                    }
                }
            }
        }

        return 0;
    }
};