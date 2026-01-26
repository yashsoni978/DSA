class Solution {
private:
    void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, int &minEdge){
        vis[node] = 1;
        for(auto &it : adj[node]){
            int nei = it.first;
            int wt = it.second;
            minEdge = min(minEdge, wt);
            if(!vis[nei]) dfs(nei, adj, vis, minEdge);
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &r : roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        vector<int>vis(n+1,0);
        int minEdge = INT_MAX;
        dfs(1, adj, vis, minEdge);
        return minEdge;
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &r : roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        vector<int>vis(n+1,0);
        int minEdge = INT_MAX;
        queue<int>q;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it : adj[node]){
                int nei = it.first;
                int wt = it.second;
                minEdge = min(minEdge, wt);
                if(!vis[nei]){
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
        return minEdge;
    }
};

class Solution {
public:
    vector<int> parent, rank;

    int findUPar(int node) {

        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {

        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pv] < rank[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0; i<n; i++) parent[i] = i;
        for(auto &r : roads) unionByRank(r[0],r[1]);
        int comp = findUPar(1), minEdge = INT_MAX;
        for(auto &r : roads){
            int u = r[0], wt = r[2];
            if(comp == findUPar(u)) minEdge = min(minEdge, wt);
        }
        return minEdge;
    }
};