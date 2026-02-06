class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        int n = matrix.size();
        if(j < 0 || j >= n) return 1e9;
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int leftDiagonal = matrix[i][j] + solve(i-1, j-1, matrix, dp);
        int up = matrix[i][j] + solve(i-1, j, matrix, dp);
        int rightDiagonal = matrix[i][j] + solve(i-1, j+1, matrix, dp);
        return dp[i][j] = min({leftDiagonal, up, rightDiagonal});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        int ans = 1e9;
        for(int j=0; j<n; j++) ans = min(ans, solve(n-1, j, matrix, dp));
        return ans;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int j=0; j<n; j++) dp[0][j] = matrix[0][j];
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){//falling path can start/end at any column → must process all columns
                int leftDiag = 1e9;
                if(j-1 >= 0) leftDiag = matrix[i][j] + dp[i-1][j-1];
                int up = 1e9;
                up = matrix[i][j] + dp[i-1][j];
                int rightDiag = 1e9;
                if(j+1 < n) rightDiag = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min({leftDiag, up, rightDiag});
            }
        }
        int ans = 1e9;
        for(int j=0; j<n; j++) ans = min(ans, dp[n-1][j]);
        return ans;
    }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev(n,0);
        for(int j=0; j<n; j++) prev[j] = matrix[0][j];
        for(int i=1; i<n; i++){
            vector<int>curr(n,0);
            for(int j=0; j<n; j++){//falling path can start/end at any column → must process all columns
                int leftDiag = 1e9;
                if(j-1 >= 0) leftDiag = matrix[i][j] + prev[j-1];
                int up = 1e9;
                up = matrix[i][j] + prev[j];
                int rightDiag = 1e9;
                if(j+1 < n) rightDiag = matrix[i][j] + prev[j+1];
                curr[j] = min({leftDiag, up, rightDiag});
            }
            prev = curr;
        }
        int ans = 1e9;
        for(int j=0; j<n; j++) ans = min(ans, prev[j]);
        return ans;
    }
};