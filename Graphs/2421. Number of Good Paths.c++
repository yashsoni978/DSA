class Solution {
public:
    vector<int>parent,size;
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu = findUPar(u), pv = findUPar(v);
        if(pu == pv) return;
        if(pu < pv){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        size.resize(n,0);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        map<int, vector<int>>valueToNodes;
        for(int i=0; i<n; i++) valueToNodes[vals[i]].push_back(i);
        vector<bool>active(n, false);
        int goodPaths = n;
        for(auto &it : valueToNodes){
            vector<int>& nodes = it.second; 
            for(int node : nodes){
                for(int nei : adj[node]){
                    if(active[nei]) unionBySize(node, nei);
                }
                active[node] = true;
            }
            unordered_map<int,int>componentCnt;
            for(int node : nodes){
                int root = findUPar(node);
                componentCnt[root]++;
            }
            for(auto &it2 : componentCnt){
                int cnt = it2.second;
                goodPaths += (cnt * (cnt-1))/2;
            }
        }
        return goodPaths;
    }
};class Solution {
public:
    vector<int>parent,size;
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu = findUPar(u), pv = findUPar(v);
        if(pu == pv) return;
        if(pu < pv){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n);
        size.resize(n,0);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        map<int, vector<int>>valueToNodes;
        for(int i=0; i<n; i++) valueToNodes[vals[i]].push_back(i);
        vector<bool>active(n, false);
        int goodPaths = n;
        for(auto &it : valueToNodes){
            vector<int>& nodes = it.second; 
            for(int node : nodes){
                for(int nei : adj[node]){
                    if(active[nei]) unionBySize(node, nei);
                }
                active[node] = true;
            }
            unordered_map<int,int>componentCnt;
            for(int node : nodes){
                int root = findUPar(node);
                componentCnt[root]++;
            }
            for(auto &it2 : componentCnt){
                int cnt = it2.second;
                goodPaths += (cnt * (cnt-1))/2;
            }
        }
        return goodPaths;
    }
};