class Solution {
private:
    bool dfs(int node, vector<int>& edges, vector<int>& vis, vector<int>& pathVis, vector<int>& cnt, int &res){
        vis[node] = 1;
        pathVis[node] = 1;
        int next = edges[node];
        if(next != -1){
            if(!vis[next]){
                cnt[next] = 1 + cnt[node];
                dfs(next, edges, vis, pathVis, cnt, res);
            }
            else if(pathVis[next]){
                int cycleLength = cnt[node] - cnt[next] + 1;
                res = max(res, cycleLength);
            }
        }
        pathVis[node] = 0;
        return false;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>vis(n,0), pathVis(n,0), cnt(n,0);
        int res = -1;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt[i] = 1;
                dfs(i, edges, vis, pathVis, cnt, res);
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>indegree(n,0);
        for(int i=0; i<n; i++){
            if(edges[i] != -1) indegree[edges[i]]++;
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int next = edges[node];
            if(next != -1){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }
        vector<bool>vis(n, false);
        int res = -1;
        for(int i=0; i<n; i++){
            if(indegree[i] > 0 && !vis[i]){
                int curr = i, cnt = 0;
                while(!vis[curr]){
                    vis[curr] = true;
                    curr = edges[curr];
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};

