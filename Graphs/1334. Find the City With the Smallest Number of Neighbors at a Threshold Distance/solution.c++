class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = INT_MAX;
        vector<vector<int>>dist(n, vector<int>(n, INF));
        for(auto it : edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int i=0; i<n; i++) dist[i][i] = 0;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(dist[i][k] != INF && dist[k][j] != INF){
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        int cntCity = n, cityNo = -1;
        for(int city=0; city<n; city++){
            int cnt = 0;
            for(int adjCity = 0; adjCity < n; adjCity++){
                if(dist[city][adjCity] <= distanceThreshold) cnt++;
            }
            if(cnt <= cntCity){
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};

/*TC: O(N³) — Floyd-Warshall dominates; initialization and counting take O(N²), and processing edges takes O(E).
SC: O(N²) — Uses an N × N distance matrix to store shortest distances between every pair of cities.*/