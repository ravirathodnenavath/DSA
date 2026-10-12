class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        const int INF = 1e9;
        vector<int> price(n, INF);
        price[src] = 0;

        // At most k stops means at most k+1 flights
        for (int i = 0; i <= k; i++) {
            vector<int> temp = price;

            for (auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];

                if (price[u] != INF &&
                    price[u] + cost < temp[v]) {
                    temp[v] = price[u] + cost;
                }
            }

            price = temp;
        }

        return price[dst] == INF ? -1 : price[dst];
    }
};