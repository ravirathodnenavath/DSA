class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        using ll = long long;

        vector<vector<pair<int,int>>> adj(n);

        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int time = road[2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        vector<ll> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        // {distance, node}
        priority_queue<
            pair<ll,int>,
            vector<pair<ll,int>>,
            greater<pair<ll,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto& [neighbor, time] : adj[node]) {
                ll newDist = d + time;

                if (newDist < dist[neighbor]) {
                    // Found a shorter path
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.push({newDist, neighbor});
                }
                else if (newDist == dist[neighbor]) {
                    // Found another shortest path
                    ways[neighbor] =
                        (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};