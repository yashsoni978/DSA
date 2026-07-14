class Solution {
private:
    int timer = 1;
private:
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& adj, vector<vector<int>>& bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, vis, tin, low, adj, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) bridges.push_back({it, node});
            }
            else low[node] = min(low[node], low[it]);
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto &e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0),tin(n),low(n);
        vector<vector<int>>bridges;
        dfs(0, -1, vis, tin, low, adj, bridges);
        return bridges;
    }
};

/*TC: O(V + E) — Tarjan's DFS visits each vertex once and processes each edge at most twice.
SC: O(V + E) — Uses adjacency list, vis/tin/low arrays, recursion stack, and stores the bridge edges.*/