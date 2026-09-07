class Solution {
private:
    void dfs(int Node, vector<vector<int>>& adjList, vector<int>& Vis) {

        // Mark current node as visited
        Vis[Node] = 1;

        // Visit all neighbours of Node
        for (auto it : adjList[Node]) {
            if (!Vis[it]) {
                dfs(it, adjList, Vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        // Number of vertices
        int V = isConnected.size();

        // Visited array
        vector<int> Vis(V, 0);

        // Adjacency List
        vector<vector<int>> adjList(V);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }

        // Count connected components
        int cnt = 0;

        for (int i = 0; i < V; i++) {
            if (!Vis[i]) {
                cnt++;
                dfs(i, adjList, Vis);
            }
        }
        return cnt;
    }
};