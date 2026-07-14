class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j && isConnected[i][j] == 1) adj[i].push_back(j);
            }
        }
        vector<int>vis(n,0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, adj);
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        DisjointSet ds(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1) {
                    ds.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (ds.parent[i] == i) cnt++;
        }

        return cnt;
    }
};

/*TC: O(V² × α(V)) ≈ O(V²) — Traverse the V × V adjacency matrix and perform nearly constant-time DSU union/find operations.
SC: O(V) — Uses parent and size arrays of the Disjoint Set.*/
