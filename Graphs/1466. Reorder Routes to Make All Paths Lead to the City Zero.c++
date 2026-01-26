class Solution {
private:
    void dfs(int node, int parent, vector<vector<pair<int,int>>>& adj, int &reorderCnt){
        for(auto &it : adj[node]){
            int nei = it.first;
            int cost = it.second;
            if(nei == parent) continue;
            reorderCnt += cost;
            dfs(nei, node, adj, reorderCnt);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e : connections){
            adj[e[0]].push_back({e[1],1});
            adj[e[1]].push_back({e[0],0});
        }
        int reorderCnt = 0;
        dfs(0, -1, adj, reorderCnt);
        return reorderCnt;
    }
};

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e : connections){
            adj[e[0]].push_back({e[1],1});
            adj[e[1]].push_back({e[0],0});
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        int reorderCnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it : adj[node]){
                int nei = it.first;
                int cost = it.second;
                if(!vis[nei]){
                    reorderCnt += cost;
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
        return reorderCnt;
    }
};