class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        // -1 = unvisited, 0 and 1 = two different groups
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {

            // Graph can have multiple disconnected components
            if (color[start] != -1)
                continue;

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                for (int neighbour : graph[node]) {

                    if (color[neighbour] == -1) {

                        // Neighbour must have opposite color
                        color[neighbour] = 1 - color[node];
                        q.push(neighbour);
                    }

                    else if (color[neighbour] == color[node]) {

                        // Adjacent nodes have same color → not bipartite
                        return false;
                    }
                }
            }
        }

        return true;
    }
};