class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, long long &compSize){
        vis[node] = 1;
        compSize++;
        for(auto &nei : adj[node]){
            if(!vis[nei]) dfs(nei, adj, vis, compSize);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0);
        long long remainingNodes = n, ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                long long compSize = 0;
                dfs(i, adj, vis, compSize);
                ans += compSize * (remainingNodes - compSize);
                remainingNodes -= compSize;
            }
        }
        return ans;
    }
};

class Solution {
private:
    void bfs(int start, vector<vector<int>>& adj, vector<int>& vis, long long &compSize){
        vis[start] = 1;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            compSize++;
            for(auto &nei : adj[node]){
                if(!vis[nei]){
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0);
        long long remainingNodes = n, ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                long long compSize = 0;
                bfs(i, adj, vis, compSize);
                ans += compSize * (remainingNodes - compSize);
                remainingNodes -= compSize;
            }
        }
        return ans;
    }
};