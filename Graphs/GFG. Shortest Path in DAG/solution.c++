class Solution {
  private:
    void topoSort(int node, vector<int>& vis, stack<int>& st, vector<vector<pair<int,int>>>& adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]) topoSort(v, vis, st, adj);
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto &e : edges) adj[e[0]].push_back({e[1],e[2]});
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0; i<V; i++){
            if(!vis[i]) topoSort(i, vis, st, adj);
        }
        vector<int>dist(V,INT_MAX);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it : adj[node]){
                int v = it.first, wt = it.second;
                if(dist[node] != INT_MAX && dist[node] + wt < dist[v]) dist[v] = wt + dist[node];
            }
        }
        for(int i=0; i<V; i++){
            if(dist[i] == INT_MAX) dist[i] = -1;// as said in ques
        }
        return dist;
    }
};
/*Complexity
Topological Sort (DFS): O(V + E)
Distance Relaxation: O(E)
Overall: O(V + E)
Space: O(V + E)*/
