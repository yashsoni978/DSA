class Solution {
private:
    char dfs(char node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node - 'a'] = 1;
        char smallest = node;
        for(int nei : adj[node - 'a']){
            char nextChar = nei + 'a';
            if(!vis[nei]) smallest = min(smallest, dfs(nextChar, adj, vis));
        }
        return smallest;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>>adj(26);
        for(int i=0; i<s1.size(); i++){
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string res = "";
        for(char ch : baseStr){
            vector<int>vis(26,0);
            char smallestChar = dfs(ch, adj, vis);
            res.push_back(smallestChar);
        }
        return res;
    }
};

class Solution {
private:
    char bfs(char start, vector<vector<int>>& adj){
        vector<int>vis(26,0);
        queue<int>q;
        q.push(start - 'a');
        vis[start - 'a'] = 1;
        char smallest = start;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            smallest = min(smallest, char(node + 'a'));
            for(int nei : adj[node]){
                if(!vis[nei]){
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
        return smallest;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>>adj(26);
        for(int i=0; i<s1.length(); i++){
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string res = "";
        for(char ch : baseStr) res.push_back(bfs(ch, adj));
        return res;
    }
};

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
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        size.resize(26);
        for(int i=0; i<26; i++){
            parent[i] = i;
            size[i] = 1;
        }
        for(int i=0; i<s1.size(); i++) unionBySize(s1[i] - 'a', s2[i] - 'a');
        string res = "";
        for(char ch : baseStr){
            int root = findUPar(ch - 'a');
            res.push_back(root + 'a');
        }
        return res;
    }
};