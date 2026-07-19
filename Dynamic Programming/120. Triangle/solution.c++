class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle, int n){
        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + solve(i+1, j, dp, triangle, n);
        int diag = triangle[i][j] + solve(i+1, j+1, dp, triangle, n);
        return dp[i][j] = min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return solve(0, 0, dp, triangle, n);
    }
};

/*TC: O(n²) — Each triangle cell is solved only once using memoization.
SC: O(n²) — O(n²) for the DP table and O(n) recursive call stack.*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int j=0; j<n; j++) dp[n-1][j] = triangle[n-1][j];
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
};

/*TC: O(n²) — Computes the minimum path sum for each triangle cell once using tabulation.
SC: O(n²) — Uses a DP table of size n × n.*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>prev(n,0);
        for(int j=0; j<n; j++) prev[j] = triangle[n-1][j];
        for(int i=n-2; i>=0; i--){
            vector<int>curr(n,0);
            for(int j=i; j>=0; j--){
                int down = triangle[i][j] + prev[j];
                int diag = triangle[i][j] + prev[j+1];
                curr[j] = min(down, diag);
            }
            prev = curr;
        }
        return prev[0];
    }
};