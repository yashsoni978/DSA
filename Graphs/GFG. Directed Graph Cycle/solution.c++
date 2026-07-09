class Solution {
  private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj){
        vis[node] = 1;
        pathVis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, adj) == true) return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &e : edges) adj[e[0]].push_back(e[1]);
        vector<int>vis(V,0), pathVis(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj) == true) return true;
            }
        }
        return false;
    }
};