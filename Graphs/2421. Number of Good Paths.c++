class Solution {
public:

    vector<int> parent, rank;

    int findUPar(int node) {

        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {

        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {

        int n = vals.size();

        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Value -> nodes mapping (sorted automatically)
        map<int, vector<int>> valueToNodes;

        for (int i = 0; i < n; i++) {
            valueToNodes[vals[i]].push_back(i);
        }

        vector<bool> active(n, false);

        int goodPaths = n; // Every node itself is a good path

        // Process values in increasing order
        for (auto &it : valueToNodes) {

            vector<int> &nodes = it.second;

            // Step 1: Activate nodes & union with active neighbors
            for (int node : nodes) {

                for (int neigh : adj[node]) {
                    if (active[neigh]) {
                        unionByRank(node, neigh);
                    }
                }

                active[node] = true;
            }

            // Step 2: Count nodes with same parent
            unordered_map<int, int> componentCount;

            for (int node : nodes) {
                int root = findUPar(node);
                componentCount[root]++;
            }

            // Step 3: Count combinations
            for (auto &it2 : componentCount) {
                int cnt = it2.second;
                goodPaths += (cnt * (cnt - 1)) / 2;
            }
        }

        return goodPaths;
    }
};
