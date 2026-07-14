class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt = 0;
        vector<int>ans;
        for(auto it : operators){
            int row = it[0], col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            vector<int>delRow = {-1,0,1,0};
            vector<int>delCol = {0,-1,0,1};
            for(int i=0; i<4; i++){
                int adjr = row + delRow[i];
                int adjc = col + delCol[i];
                if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m && vis[adjr][adjc] == 1){
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;
                    if(ds.findPar(nodeNo) != ds.findPar(adjNodeNo)){
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

/*TC: O(K × α(N × M)) ≈ O(K) — Each operation checks only 4 neighbors and performs nearly constant-time DSU operations.
SC: O(N × M + K) — Uses DSU arrays, a visited matrix of size N × M, and an answer vector of size K.*/