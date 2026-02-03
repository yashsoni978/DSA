class Solution {
private:
    int dfs(int node, int parent, vector<vector<int>>& adj, string &s, int &maxPath){
        int longestChildPath = 0, secondLongestChildPath = 0;
        for(int child : adj[node]){
            if(child == parent) continue;
            int childPath = dfs(child, node, adj, s, maxPath);
            if(s[child] == s[node]) continue; // We dont want adjacent chars to be same
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

//Hindi variables(more understandable)
class Solution {
private:
    int dfs(int node, int parent, vector<vector<int>>& adj, string &s, int &longestPath){
        int longest = 0, sLongest = 0;
        for(auto &child : adj[node]){
            if(child == parent) continue;
            int childPath = dfs(child, node, adj, s, longestPath);
            if(s[child] == s[node]) continue;
            if(childPath > sLongest) sLongest = childPath; 
            if(sLongest > longest) swap(longest, sLongest);
        }
        int koi_ek_acha = max(longest,sLongest) + 1;
        int root_acha = 1;
        int neeche_mila = longest + sLongest + 1;
        longestPath = max({longestPath, koi_ek_acha, root_acha, neeche_mila});
        return max(koi_ek_acha, root_acha);
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>adj(n);
        for(int i=1; i<n; i++){
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }
        int longestPath = INT_MIN;
        dfs(0, -1, adj, s, longestPath);
        return longestPath;
    }
};
