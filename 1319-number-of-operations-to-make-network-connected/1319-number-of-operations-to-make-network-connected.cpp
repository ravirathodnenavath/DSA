class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // At least n-1 cables are required
        if (connections.size() < n - 1)
            return -1;

        vector<vector<int>> adj(n);

        for (auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, adj, visited);
            }
        }

        // Connect all components using components - 1 cables
        return components - 1;
    }
};