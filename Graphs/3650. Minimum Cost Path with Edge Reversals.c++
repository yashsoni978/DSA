class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e : edges){
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u, 2*wt});
        }
        vector<int>dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int currDist = it.first;
            int node = it.second;
            if(currDist > dist[node]) continue;
            if(node == n-1) return currDist;
            for(auto &edge : adj[node]){
                int nei = edge.first;
                int wt = edge.second;
                if(currDist + wt < dist[nei]){
                    dist[nei] = currDist + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        return -1;
    }
};