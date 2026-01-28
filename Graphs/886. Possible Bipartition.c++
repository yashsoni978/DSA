class Solution {
private:
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& adj){
        color[node] = col;
        for(auto it : adj[node]){
            if(color[it] == -1){
                if(!dfs(it, 1-col, color, adj)) return false;
            }
            if(color[it] == color[node]) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto &d : dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(!dfs(i, 0, color, adj)) return false;
            }
        }
        return true;
    }
};

class Solution {
private:
    bool bfs(int src, int col, vector<int>& color, vector<vector<int>>& adj){
        color[src] = col;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]) return false;
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto &d : dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1; i<=n; i++){
            if(color[i] == -1){
                if(!bfs(i, 0, color, adj)) return false;
            }
        }
        return true;
    }
};