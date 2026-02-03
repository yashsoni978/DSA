class Solution {
private:
    bool isSimilar(string &s1, string &s2){
        int n = s1.length();
        int diff = 0;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]) diff++;
        }
        return diff == 0 || diff == 2;
    }
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, vis, adj);
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
private:
    bool isSimilar(string &s1, string &s2){
        int n = s1.length();
        int diff = 0;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]) diff++;
        }
        return diff == 0 || diff == 2;
    }
    void bfs(int start, vector<int>& vis, vector<vector<int>>& adj){
        vis[start] = 1;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>>adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int>vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                bfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
private:
    bool isSimilar(string &s1, string &s2){
        int n = s1.length();
        int diff = 0;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]) diff++;
        }
        return diff == 0 || diff == 2;
    }
public:
    vector<int>parent,rank;
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int pu = findUPar(u), pv = findUPar(v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]) parent[pu] = pv;
        else if(rank[pu] > rank[pv]) parent[pv] = pu;
        else{
            parent[pu] = pv;
            rank[pu]++;
        } 
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n,0);
        rank.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        int groups = n;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isSimilar(strs[i],strs[j]) && findUPar(i) != findUPar(j)){
                    groups--;
                    unionByRank(i,j);
                }
            }
        }
        return groups;
    }
};
