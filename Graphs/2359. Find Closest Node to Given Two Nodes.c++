class Solution {
private:
    void bfs(int start, vector<int>& edges, vector<int>& dist){
        queue<int>q;
        vector<int>vis(edges.size(), 0);
        q.push(start);
        dist[start] = 0;
        vis[start] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int next = edges[node];
            if(next != -1 && !vis[next]){
                vis[next] = 1;
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dist1(n,INT_MAX), dist2(n, INT_MAX);
        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);
        int ans = -1;
        int minMaxDist = INT_MAX;
        for(int i=0; i<n; i++){
            if(dist1[i] == INT_MAX || dist2[i] == INT_MAX) continue;
            int currMax = max(dist1[i], dist2[i]);
            if(currMax < minMaxDist){
                minMaxDist = currMax;
                ans = i;
            }
        }
        return ans;
    }
};

class Solution {
private:
    void dfs(int node, vector<int>& edges, vector<int>& dist, vector<int>& vis){
        vis[node] = 1;
        int next = edges[node];
        if(next != -1 && !vis[next]){
            dist[next] = 1 + dist[node];
            dfs(next, edges, dist, vis);
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dist1(n, INT_MAX), dist2(n, INT_MAX), vis1(n,0), vis2(n,0);
        dist1[node1] = 0;
        dist2[node2] = 0;
        dfs(node1, edges, dist1, vis1);
        dfs(node2, edges, dist2, vis2);
        int minMaxDist = INT_MAX, ans = -1;
        for(int i=0; i<n; i++){
            if(dist1[i] == INT_MAX || dist2[i] == INT_MAX) continue;
            int currMax = max(dist1[i], dist2[i]);
            if(currMax < minMaxDist){
                minMaxDist = currMax;
                ans = i;
            }
        }
        return ans;
    }
};

