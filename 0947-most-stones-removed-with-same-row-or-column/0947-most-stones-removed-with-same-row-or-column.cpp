class Solution {
private:
    void dfs(int node, vector<vector<int>>& stones,
             vector<int>& vis) {
        vis[node] = 1;

        for (int i = 0; i < stones.size(); i++) {
            if (!vis[i] &&
                (stones[node][0] == stones[i][0] ||
                 stones[node][1] == stones[i][1])) {
                dfs(i, stones, vis);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n, 0);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(i, stones, vis);
            }
        }

        return n - components;
    }
};