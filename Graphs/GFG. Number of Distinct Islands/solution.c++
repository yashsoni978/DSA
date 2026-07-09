class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>>& vis, set<vector<pair<int,int>>>& st, vector<pair<int,int>>& vec, vector<vector<char>>& grid, int row0, int col0){
        int n = grid.size(), m = grid[0].size();
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0});
        vector<int>delRow = {-1,0,1,0};
        vector<int>delCol = {0,-1,0,1};
        for(int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 'L'){
                dfs(nrow, ncol, vis, st, vec, grid, row0, col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 'L'){
                    vector<pair<int,int>>vec;
                    dfs(i, j, vis, st, vec, grid, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

/*Complexity:

Time: O(N × M × log K), where K is the number of distinct island shapes (the log K comes from inserting each shape into the set).
Auxiliary Space: O(N × M) for the visited array and recursion stack in the worst case, plus storage for the distinct shapes in the set.*/