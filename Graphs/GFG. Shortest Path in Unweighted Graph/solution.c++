class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int>q;
        vector<int>dist(V,INT_MAX);
        dist[src] = 0;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        if(dist[dest] == INT_MAX) return -1;
        return dist[dest];
    }
};
