class Solution {

private:
    int timer = 1 ;

private:
    void dfs(int node, int parent, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges, vector<int> &visited, vector<int> adj[]){
        
        visited[node] = 1 ;
        tin[node] = low[node] = timer ;
        timer ++ ;
        
        for(auto it : adj[node]){
            if(it == parent) continue ;

            if(!visited[it]){

                dfs(it, node, tin, low, bridges, visited, adj) ;
                low[node] = min(low[it], low[node]) ;
                if(low[it] > tin[node]){
                    bridges.push_back({node, it}) ;
                }
            }
            // if already visited, it's in the path only, So no bridge
            else{
                low[node] = min(low[it], low[node]) ;
            }
        }
    } 

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // If the child's lowest reachable discovery time is greater than 
        // the parent's discovery time, the edge between them is a bridge.

        vector<int> adj[n] ;

        for(auto it : connections){
            int u = it[0] ;
            int v = it[1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }

        vector<int> tin(n) ;   // vector<int> tin(n, 0) ;
        vector<int> low(n) ;
        vector<int> visited(n, 0) ;
        vector<vector<int>> bridges ;

        for(int i=0; i<n; i++){
            dfs(i, -1, tin, low, bridges, visited, adj) ;
        }
        
        return bridges ;
    }
};