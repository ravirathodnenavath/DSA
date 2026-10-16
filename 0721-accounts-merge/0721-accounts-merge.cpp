class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        // Map each email to the first account containing it
        unordered_map<string, int> emailToAccount;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailToAccount.count(email)) {
                    ds.unionBySize(i, emailToAccount[email]);
                } else {
                    emailToAccount[email] = i;
                }
            }
        }

        // Group emails by their final account representative
        vector<vector<string>> merged(n);

        for (auto& [email, account] : emailToAccount) {
            int root = ds.findUPar(account);
            merged[root].push_back(email);
        }

        vector<vector<string>> result;

        for (int i = 0; i < n; i++) {
            if (merged[i].empty()) continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> account;
            account.push_back(accounts[i][0]); // Account name

            for (string& email : merged[i])
                account.push_back(email);

            result.push_back(account);
        }

        return result;
    }
};