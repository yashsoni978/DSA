// tc - m*n*2
// sc - m*n + (m+n)
class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int down = 0;
        if(j-1 >= 0) down = solve(i, j-1, dp);
        int right = 0; 
        if(i-1 >= 0) right = solve(i-1, j, dp);
        return dp[i][j] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(m-1, n-1, dp);
    }
};

// tc - m*n*2
// sc - m*n
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++) dp[i][0] = 1;
        for(int j=0; j<n; j++) dp[0][j] = 1;
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int left = 0;
                if(j-1 >= 0) left += dp[i][j-1];
                int up = 0;
                if(i - 1 >= 0) up += dp[i-1][j];
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
};

//sc - o(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,1);
        for(int i=1; i<m; i++){
            vector<int>curr(n,1);
            for(int j=1; j<n; j++){
                int left += curr[j-1];
                int up += prev[j];
                curr[j] = up + left;
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
