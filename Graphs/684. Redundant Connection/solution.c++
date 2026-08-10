class Solution {
private: 
    bool dfs(int node, int target, int parent, vector<int>& vis, vector<vector<int>>& adj){
        if(node == target) return true;
        vis[node] = 1;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                if(dfs(it, target, node, vis, adj)) return true;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            vector<int>vis(n+1,0);
            if(dfs(u, v, -1, vis, adj) == true) return edge;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};

//Time: O(E × (V + E)) in the worst case
//Space: O(V + E)

class Solution {
    vector<int> parent;

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            int pu = find(u);
            int pv = find(v);
            if(pu == pv) return edge;
            parent[pu] = pv;
        }
        return {};
    }
};

/*TC: O(V α(V)) ≈ O(V)
SC: O(V)*/