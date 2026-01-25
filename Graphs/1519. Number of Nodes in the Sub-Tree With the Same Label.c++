class Solution {
private:
    vector<int>dfs(int node, int parent, vector<vector<int>>& adj, string &labels, vector<int>& ans){
        vector<int>cnt(26,0);
        cnt[labels[node] - 'a'] = 1;
        for(auto it : adj[node]){
            if(it == parent) continue;
            vector<int>childCnt = dfs(it, node, adj, labels, ans);
            for(int i=0; i<26; i++) cnt[i] += childCnt[i];
        }
        ans[node] = cnt[labels[node] - 'a'];
        return cnt;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>ans(n);
        dfs(0, -1, adj, labels, ans);
        return ans;
    }
};

class Solution {
private:
    void dfs(int node, int parent, vector<vector<int>>& adj, string &labels, vector<int>& ans, vector<int>& freq){
        int before = freq[labels[node] - 'a'];
        freq[labels[node] - 'a']++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            dfs(it, node, adj, labels, ans, freq);
        }
        int after = freq[labels[node] - 'a'];
        ans[node] = after - before;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>ans(n);
        vector<int>freq(26,0);
        dfs(0, -1, adj, labels, ans, freq);
        return ans;
    }
};