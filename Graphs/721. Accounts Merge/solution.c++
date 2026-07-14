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
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        DisjointSet ds(n);
        unordered_map<string,int>mapMailNode;
        for(int i=0; i<n; i++){
            for(int j=1; j<details[i].size(); j++){
                string mail = details[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()) mapMailNode[mail] = i;
                else ds.unionBySize(i, mapMailNode[mail]);
            }
        }
        vector<vector<string>>mergedMail(n);
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.findPar(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string>temp;
            temp.push_back(details[i][0]);
            for(auto it : mergedMail[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};

/*TC: O(M log M + M × α(N)) ≈ O(M log M) — Process all emails using DSU and sort the merged email lists.
SC: O(M + N) — Uses DSU arrays, a hash map for email-to-account mapping, and storage for merged emails.*/