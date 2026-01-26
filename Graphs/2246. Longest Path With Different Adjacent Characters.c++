class Solution {
private:
    int dfs(int node, int parent, vector<vector<int>>& adj, string &s, int &maxPath){
        int longestChildPath = 0, secondLongestChildPath = 0;
        for(int child : adj[node]){
            if(child == parent) continue;
            int childPath = dfs(child, node, adj, s, maxPath);
            if(s[child] == s[node]) continue;
            if(childPath > longestChildPath){
                secondLongestChildPath = longestChildPath;
                longestChildPath = childPath;
            }
            else if(childPath > secondLongestChildPath) secondLongestChildPath = childPath;
        }
        maxPath = max(maxPath , longestChildPath + secondLongestChildPath + 1);
        return longestChildPath + 1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>adj(n);
        for(int i=1; i<n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int maxPath = 1;
        dfs(0, -1, adj, s, maxPath);
        return maxPath;
    }
};