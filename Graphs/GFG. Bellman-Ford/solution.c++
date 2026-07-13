class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src] = 0;
        for(int i=0; i<V-1; i++){
            for(auto it : edges){
                int u = it[0], v = it[1], wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) dist[v] = dist[u] + wt;
            }
        }
        //negative cycle
        for(int i=0; i<V-1; i++){
            for(auto it : edges){
                int u = it[0], v = it[1], wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) return {-1};
            }
        }
        return dist;
    }
};

/*TC: O(V × E) — Relax all E edges for V−1 iterations, and the extra negative cycle check still results in O(V × E).
SC: O(V) — Only the distance array of size V is used.*/