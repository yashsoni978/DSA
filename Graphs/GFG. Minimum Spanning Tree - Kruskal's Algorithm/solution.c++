/*TC: O(E log E) — Sorting the edges dominates; DSU operations (find/union) take nearly O(1) amortized, i.e., O(E × α(V)).
SC: O(E + V) — O(E) for the sorted edge list and O(V) for the parent and size arrays.*/

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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int, pair<int, int>>> e;

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            e.push_back({wt, {u, v}});
        }

        sort(e.begin(), e.end());

        DisjointSet ds(V);
        int mstWt = 0;

        for (auto &it : e) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findPar(u) != ds.findPar(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};