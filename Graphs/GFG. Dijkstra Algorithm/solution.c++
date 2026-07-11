class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int edgeWeight = it.second, adjNode = it.first;
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};



/*Complexity:

Time: O((V + E) log V)
Space: O(V + E)*/

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        st.insert({0,src});
        dist[src] = 0;
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto it : adj[node]){
                int adjNode = it.first, edgeW = it.second;
                if(dis + edgeW < dist[adjNode]){
                    if(dist[adjNode] != 1e9) st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

/*Time Complexity:
Building the adjacency list takes O(E). In Dijkstra's algorithm, each edge relaxation performs set operations (insert/erase) in O(log V), giving an overall time complexity of O((V + E) log V) (or simply O(E log V) for connected graphs).

Space Complexity:
The adjacency list requires O(V + E) space, while the distance array and set together use O(V) space. Therefore, the total auxiliary space complexity is O(V + E).*/