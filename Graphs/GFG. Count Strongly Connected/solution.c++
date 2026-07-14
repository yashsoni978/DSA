class Solution {
  private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, vis, adj, st);
        }
        st.push(node);
    }
    void dfs3(int node, vector<int>& vis, vector<vector<int>>& adjT){
        vis[node] = 1;
        for(auto it : adjT[node]){
            if(!vis[it]) dfs3(it, vis, adjT);
        }
    }
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &e : edges) adj[e[0]].push_back(e[1]);
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0; i<V; i++){
            if(!vis[i]) dfs(i, vis, adj, st);
        }
        vector<vector<int>>adjT(V);
        for(int i=0; i<V; i++){
            vis[i] = 0;//reset vis to again use the same vis array for next dfs
            for(auto it : adj[i]) adjT[it].push_back(i);
        }
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};

/*TC: O(V + E) — DFS for topological order, graph transposition, and DFS on the transposed graph each take linear time.
SC: O(V + E) — Uses adjacency lists, transpose graph, visited array, stack, and recursive DFS call stack.*/