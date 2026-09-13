class Solution {
  private:
    bool isSafe(int node, int col, vector<vector<int>>& adj, vector<int>& color){
        for(auto nei : adj[node]){
            if(color[nei] == col) return false;
        }
        return true;
    }
    bool solve(int node, int v, vector<vector<int>>& adj, vector<int>& color, int m){
        if(node == v) return true;
        for(int c=1; c<=m; c++){
            if(isSafe(node, c, adj, color)){
                color[node] = c;
                if(solve(node + 1, v, adj, color, m)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj(v);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>color(v,0);
        return solve(0, v, adj, color, m);
    }
};

/*Complexity

Let:

V = number of vertices
m = number of colors
Time: O(m^V × V) in the worst case (for each vertex, try all m colors; checking safety takes up to O(V) using an adjacency list).
Space: O(V) for the recursion stack and the color array (excluding the adjacency list).*/