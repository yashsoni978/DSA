class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid){
        if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int down = 0;
        if(j-1 >= 0) down = solve(i, j-1, dp, obstacleGrid);
        int right = 0; 
        if(i-1 >= 0) right = solve(i-1, j, dp, obstacleGrid);
        return dp[i][j] = down + right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solve(m-1, n-1, dp, obstacleGrid);
    }
};

// we can use this template also in unique Paths
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int left = 0;
                    if(j > 0) left += dp[i][j-1];
                    int up = 0;
                    if(i > 0) up += dp[i-1][j];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//here we cant blindly do prev(n,1) and curr(n,1) because it contains obstacles
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int>prev(n,0);
        for(int i=0; i<m; i++){
            vector<int>curr(n,0);
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1) curr[j] = 0;
                else if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int left = 0;
                    if(j > 0) left += curr[j-1];
                    int up = 0;
                    if(i > 0) up += prev[j];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};