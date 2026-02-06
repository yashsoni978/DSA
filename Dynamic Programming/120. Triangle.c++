class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        int n = triangle.size();
        if(i == n-1) return triangle[n-1][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = triangle[i][j] + solve(i+1, j, triangle, dp);
        int diag = triangle[i][j] + solve(i+1, j+1, triangle, dp);
        return dp[i][j] = min(down, diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        return solve(0, 0, triangle, dp);
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int j=0; j<n; j++) dp[n-1][j] = triangle[n-1][j];
        for(int i=n-2; i>=0; i--){
            //0 -> 0
            //1 -> 0,1
            //2 -> 0,1,2
            for(int j=i; j>=0; j--){
                int down = triangle[i][j];
                down += dp[i+1][j];
                int diag = triangle[i][j];
                diag += dp[i+1][j+1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>front(n,0);
        for(int j=0; j<n; j++) front[j] = triangle[n-1][j];
        for(int i=n-2; i>=0; i--){
            //0 -> 0
            //1 -> 0,1
            //2 -> 0,1,2
            vector<int>curr(n,0);
            for(int j=i; j>=0; j--){
                int down = triangle[i][j];
                down += front[j];
                int diag = triangle[i][j];
                diag += front[j+1];
                curr[j] = min(down, diag);
            }
            front = curr;;
        }
        return front[0];
    }
};

