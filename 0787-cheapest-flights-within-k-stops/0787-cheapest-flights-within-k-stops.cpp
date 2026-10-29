class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int, int>> adj[n];

        for (auto it : flights) {
            int from = it[0];
            int to = it[1];
            int cost_bw = it[2];

            adj[from].push_back({to, cost_bw});
        }

        vector<int> price(n, 1e9);
        price[src] = 0;

        // {stops, node, price/dist}
        queue<tuple<int, int, int>> q;
        q.push({0, src, 0});

        while (!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();

            // Skip paths that exceed the allowed stops
            if (stops > k) continue;

            for (auto it : adj[node]) {
                int adjcity = it.first;
                int flightPrice = it.second;

                // Update if a cheaper cost is found within the stop limit
                if (cost + flightPrice < price[adjcity] && stops <= k) {
                    price[adjcity] = cost + flightPrice;

                    // Take one more flight to reach the neighbor
                    q.push({stops + 1, adjcity, price[adjcity]});
                }
            }
        }

        // Return -1 if the destination is unreachable
        if (price[dst] == 1e9) return -1;

        return price[dst];
    }
};