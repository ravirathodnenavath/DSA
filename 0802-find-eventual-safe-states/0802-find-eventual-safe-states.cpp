class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> reverseGraph(n);
        vector<int> indegree(n, 0);

        // Reverse every edge
        for (int i = 0; i < n; i++) {
            for (int next : graph[i]) {

                reverseGraph[next].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        // Terminal nodes have no outgoing edges
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            safe.push_back(node);

            // Check nodes that point to the current node
            for (int prev : reverseGraph[node]) {

                indegree[prev]--;

                if (indegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        // Problem requires answer in sorted order
        sort(safe.begin(), safe.end());

        return safe;
    }
};