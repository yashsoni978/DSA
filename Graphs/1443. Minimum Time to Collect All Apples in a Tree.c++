class Solution {
private:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& hasApple){
        int totalTime = 0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            int childTime = dfs(it, node, adj, hasApple);
            if(childTime > 0 || hasApple[it]) totalTime += childTime + 2;
        }
        return totalTime;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(0, -1, adj, hasApple);
    }
};

