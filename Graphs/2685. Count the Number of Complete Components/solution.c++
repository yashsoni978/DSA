class Solution {
private:
    void dfs(int node, int &vertices, int &edges, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        vertices++;
        edges += adj[node].size();// 0 -> {1,2} count the size of it ie 2
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, vertices, edges, vis, adj);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(vis[i]) continue;
            int vertices = 0, edgeCount = 0;
            dfs(i, vertices, edgeCount, vis, adj);
            if(edgeCount == vertices * (vertices - 1)) cnt++; //every edge is counted twice using formula nC2
        }
        return cnt;
    }
};

class Solution {
private:
    void bfs(int node, int &vertices, int &edges, vector<int>& vis, vector<vector<int>>& adj){
        queue<int>q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            vertices++;
            edges += adj[curr].size();
            for(auto it : adj[curr]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it); 
                }
            }
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n,0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(vis[i]) continue;
            int vertices = 0, edgeCount = 0;
            bfs(i, vertices, edgeCount, vis, adj);
            if(edgeCount == vertices * (vertices - 1)) cnt++;
        }
        return cnt;
    }
};

class DisjointSet {

public:
    vector<int> parent, size;

    DisjointSet(int n) {

        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {

        if(node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto &it : edges) ds.unionBySize(it[0],it[1]);
        unordered_map<int,int>edgeCount;
        for(auto &it : edges){
            int parent = ds.findUPar(it[0]);
            edgeCount[parent]++;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(ds.findUPar(i) != i) continue; //if not parent then skip
            int vertices = ds.size[i];//stored in size array
            int edgesInComp = edgeCount[i];
            if(edgesInComp == (vertices * (vertices - 1)) / 2) cnt++;
        }
        return cnt;
    }
};