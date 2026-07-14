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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0) continue;//no need to change
                vector<int>delRow = {0,-1,0,1};
                vector<int>delCol = {-1,0,1,0};
                for(int i=0; i<4; i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        int nodeNo = row * n + col;
                        int adjNodeNo = nrow * n + ncol;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        int mx = 0;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 1) continue;//because here we change 0's only
                vector<int>delRow = {-1,0,1,0};
                vector<int>delCol = {0,-1,0,1};
                set<int>components;
                for(int i=0; i<4; i++){
                    int nrow = row + delRow[i];
                    int ncol = col + delCol[i];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                        components.insert(ds.findPar(nrow * n + ncol));
                    }
                }
                int sizeTotal = 0;
                for(auto it : components) sizeTotal += ds.size[it];
                mx = max(mx, sizeTotal + 1);//+1 for the 0 turned into 1
            }
        }
        for(int cellNo = 0; cellNo < n*n; cellNo++) mx = max(mx, ds.size[ds.findPar(cellNo)]);//if all have 1's
        return mx;
    }
};

/*TC: O(N² × α(N²)) ≈ O(N²) — Traverse the grid multiple times, checking 4 neighbors per cell and performing nearly constant-time DSU operations.
SC: O(N²) — Uses DSU parent and size arrays; the temporary set stores at most 4 components.*/