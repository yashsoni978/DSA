class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        const int INF = 1e8;

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] != INF && dist[k][j] != INF){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};

//TC: O(V³) — Three nested loops check every pair of vertices using every vertex as an intermediate.
//SC: O(1) — Updates the given distance matrix in-place without using any extra space.