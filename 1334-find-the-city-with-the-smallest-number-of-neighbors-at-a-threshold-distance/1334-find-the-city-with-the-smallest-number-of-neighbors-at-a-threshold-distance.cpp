class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(n, INF));

        // Distance from a city to itself is zero
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        // Build the undirected graph
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall: shortest paths between all pairs
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] != INF &&
                        dist[via][j] != INF) {
                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][via] + dist[via][j]
                        );
                    }
                }
            }
        }

        int answer = -1;
        int minCount = INT_MAX;

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    count++;
            }

            // >= ensures ties choose the city with the greatest index
            if (count <= minCount) {
                minCount = count;
                answer = i;
            }
        }

        return answer;
    }
};