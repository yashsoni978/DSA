class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = solve(i-1, j, dp);
        int left = solve(i, j-1, dp);
        return dp[i][j] = up + left;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(m-1, n-1, dp);
    }
};

/*TC: O(m × n) — Each grid cell is solved only once using memoization.
SC: O(m × n) — O(m × n) for the DP table and O(m + n) recursive call stack.*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0;
                if(i - 1 >= 0) up = dp[i-1][j];
                int left = 0;
                if(j - 1 >= 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
};

/*TC: O(m × n) — Computes the number of unique paths for each grid cell once using tabulation.
SC: O(m × n) — Uses a DP table of size m × n.*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int i=0; i<m; i++){
            vector<int>curr(n,0);
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0){
                    curr[j] = 1;
                    continue;
                }
                int up = 0;
                if(i - 1 >= 0) up = prev[j];
                int left = 0;
                if(j - 1 >= 0) left = curr[j-1];
                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n-1];
    }
};

/*TC: O(m × n) — Computes the number of unique paths for each grid cell once using space-optimized DP.
SC: O(n) — Uses two 1D arrays of size n instead of a 2D DP table.*/