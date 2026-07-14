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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto &it : connections){
            int u = it[0], v = it[1];
            if(ds.findPar(u) == ds.findPar(v)) cntExtras++;
            else ds.unionBySize(u,v);
        }
        int cntC = 0;
        for(int i=0; i<n; i++){
            if(ds.findPar(i) == i) cntC++;
        }
        int ans = cntC - 1;
        if(cntExtras >= ans) return ans;
        return -1;
    }
};

/*TC: O((E + N) × α(N)) ≈ O(E + N) — Process all edges and count connected components using nearly constant-time DSU operations.
SC: O(N) — Uses parent and size arrays of the Disjoint Set.*/