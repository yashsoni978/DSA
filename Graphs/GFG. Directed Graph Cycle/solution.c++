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

//topo sort
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &e : edges) adj[e[0]].push_back(e[1]);
        vector<int>indegree(V,0);
        for(int i=0; i<V; i++){
            for(auto it : adj[i]) indegree[it]++;
        }
        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(cnt != V) return true;
        return false;
    }
};
