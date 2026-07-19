class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid){
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int up = grid[i][j] + solve(i-1, j, dp, grid);
        int left = grid[i][j] + solve(i, j-1, dp, grid);
        return dp[i][j] = min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(m-1, n-1, dp, grid);
    }
};

/*TC: O(m × n) — Each grid cell is solved only once using memoization.
SC: O(m × n) — O(m × n) for the DP table and O(m + n) recursive call stack.*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i > 0) up += dp[i-1][j];
                    else up += 1e9;
                    int left = grid[i][j];
                    if(j > 0) left += dp[i][j-1];
                    else left += 1e9;
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

/*TC: O(m × n) — Computes the minimum path sum for each grid cell once using tabulation.
SC: O(m × n) — Uses a DP table of size m × n.*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>prev(n,0);
        for(int i=0; i<m; i++){
            vector<int>curr(n,0);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) curr[j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i > 0) up += prev[j];
                    else up += 1e9;
                    int left = grid[i][j];
                    if(j > 0) left += curr[j-1];
                    else left += 1e9;
                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};