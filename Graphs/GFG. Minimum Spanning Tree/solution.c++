class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,0});
        int sum = 0;
        //E
        while(!pq.empty()){
          //log E
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            //E log E
            for(auto it : adj[node]){
                int adjNode = it.first, edgeW = it.second;
                if(!vis[adjNode]) pq.push({edgeW, adjNode});
            }
        }
        return sum;
    }
};

//tc :- E log E + E log E
//sc :- E + V(vis)