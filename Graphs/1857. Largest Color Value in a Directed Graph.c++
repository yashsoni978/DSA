class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int>q;
        vector<vector<int>>t(n, vector<int>(26,0));
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }
        int cntNodes = 0;
        int ans = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cntNodes++;
            ans = max(ans, t[u][colors[u] - 'a']);
            for(int &v : adj[u]){
                for(int i=0; i<26; i++){
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v] - 'a' == i));
                }
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        if(cntNodes < n) return -1;
        return ans;
    }
};

class Solution {
private:
    bool dfs(int u, vector<vector<int>>& adj, string &colors, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& t){
        vis[u] = 1;
        pathVis[u] = 1;
        t[u][colors[u] - 'a'] = 1;
        for(int v : adj[u]){
            if(!vis[v]){
                if(dfs(v, adj, colors, vis, pathVis, t)) return true;
            }
            else if(pathVis[v]) return true;
            for(int i=0; i<26; i++) t[u][i] = max(t[u][i], t[v][i] + (colors[u] - 'a' == i));
        }
        pathVis[u] = 0;
        return false;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>>adj(n);
        for(auto &e : edges) adj[e[0]].push_back(e[1]);
        vector<vector<int>>t(n, vector<int>(26,0));
        vector<int>vis(n,0),pathVis(n,0);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, adj, colors, vis, pathVis, t)) return -1;
            }
        }
        for(int i=0; i<n; i++){
            for(int c=0; c<26; c++) ans = max(ans, t[i][c]);
        }
        return ans;
    }
};