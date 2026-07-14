class Solution {
public:
    int findParent(int x, vector<int> &parent) {
        if (parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }

    vector<int> DSU(int n, vector<vector<int>>& queries) {
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        vector<int> ans;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int px = findParent(q[1], parent);
                int pz = findParent(q[2], parent);
                if (px != pz) parent[px] = pz;
            } else {
                ans.push_back(findParent(q[1], parent));
            }
        }

        return ans;
    }
};