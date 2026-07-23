class Solution {
  private:
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k=i; k<=j-1; k++){
            int cost = solve(i, k, arr, dp) + solve(k+1, j, arr, dp) + arr[i-1] * arr[k] * arr[j];
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return solve(1, n-1, arr, dp);
    }
};

/*TC: O(n³) — For every interval (i, j), try all partition points k and compute the minimum multiplication cost.
SC: O(n²) + O(n) — Uses a 2D DP table for memoization and O(n) recursion stack depth.*/

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int i=1; i<n; i++) dp[i][i] = 0;
        for(int i=n-1; i>=1; i--){
            for(int j=i+1; j<n; j++){//cant write j=0 because i will always be on left of j
                int mini = INT_MAX;
                for(int k=i; k<j; k++){
                    int cost = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
};

/*TC: O(n³) — For every interval (i, j), try all possible partition points k and compute the minimum multiplication cost.
SC: O(n²) — Uses a 2D DP table where dp[i][j] stores the minimum cost to multiply matrices from i to j.*/