class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>res(n,0);
        for(int i=0; i<n; i++){
            queue<int>q;
            q.push(i);
            vector<int>vis(n,0);
            vis[i] = 1;
            int dist = 0;
            while(!q.empty()){
                int size = q.size();
                while(size--){
                    int node = q.front();
                    q.pop();
                    res[i] += dist;
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push(it);
                        }
                    }
                }
                dist++;
            }
        }
        return res;
    }
};

/*So DFS must know:

Which node is the starting point

Where we are currently

Distance from start

Avoid going backward in tree*/
class Solution {
private:
    void dfs(int src, int node, int parent, int depth, vector<vector<int>>& adj, vector<int>& res){
        res[src] += depth;
        for(auto it : adj[node]){
            if(it != parent) dfs(src, it, node, depth+1, adj, res);
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>res(n,0);
        for(int i=0; i<n; i++){
            dfs(i, i, -1, 0, adj, res);
        }
        return res;
    }
};

class Solution {
public:
    long resBase = 0;
    vector<int>cnt;
    int N;
    int dfsBase(vector<vector<int>>& adj, int node, int prevNode, int depth){
        int totalNodes = 1;
        resBase += depth;
        for(int &child : adj[node]){
            if(child == prevNode) continue;
            totalNodes += dfsBase(adj, child, node, depth + 1);
        }
        cnt[node] = totalNodes;
        return totalNodes;
    }
    void dfs(vector<vector<int>>& adj, int parent, int prevNode, vector<int>& res){
        for(int &child : adj[parent]){
            if(child == prevNode) continue;
            res[child] = res[parent] - cnt[child] + (N - cnt[child]);
            dfs(adj, child, parent, res);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        N = n;
        cnt.resize(n,0);
        resBase = 0;
        dfsBase(adj, 0, -1, 0);
        vector<int>res(n,0);
        res[0] = resBase;
        dfs(adj, 0, -1, res);
        return res;
    }
};