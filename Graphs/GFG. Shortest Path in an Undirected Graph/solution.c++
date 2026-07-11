class Solution {
public:

    vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src){
        vector<int> dist(V+1, 1e9);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;

                if(dis + edgeW < dist[adjNode]){
                    dist[adjNode] = dis + edgeW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }

    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {

        vector<vector<pair<int,int>>> adj(V+1);

        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        for(int i=1; i<=V; i++)
            sort(adj[i].begin(), adj[i].end());

        vector<int> distSrc = dijkstra(V, adj, src);
        vector<int> distDest = dijkstra(V, adj, dest);

        if(distSrc[dest] == 1e9)
            return {-1};

        vector<int> path;

        int node = src;
        path.push_back(node);

        while(node != dest){

            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;

                if(distSrc[node] + edgeW + distDest[adjNode] == distSrc[dest]){//for multiple shortest paths
                    path.push_back(adjNode);
                    node = adjNode;
                    break;
                }
            }
        }

        return path;
    }
};