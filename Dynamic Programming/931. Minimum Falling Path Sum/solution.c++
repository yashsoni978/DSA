class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        int n = matrix.size();
        if(j < 0 || j >= n) return 1e9;
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int down = matrix[i][j] + solve(i-1, j, dp, matrix);
        int leftD = matrix[i][j] + solve(i-1, j-1, dp, matrix);
        int rightD = matrix[i][j] + solve(i-1, j+1, dp, matrix);
        return dp[i][j] = min({down, leftD, rightD});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,-1));
        int ans = INT_MAX;
        for(int j=0; j<n; j++) ans = min(ans, solve(n-1, j, dp, matrix));//Ans can end on any column in the last row
        return ans;
    }
};

/*TC: O(n²) — Each matrix cell is solved only once using memoization; checking the last row adds O(n).
SC: O(n²) — O(n²) for the DP table and O(n) recursive call stack.*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n, vector<int>(n,0));
        for(int j=0; j<n; j++) dp[0][j] = matrix[0][j];
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int leftD = 1e9;
                if(j - 1 >= 0) leftD = matrix[i][j] + dp[i-1][j-1];
                int rightD = 1e9;
                if(j + 1 < n) rightD = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min({up, leftD, rightD});
            }
        }
        int ans = 1e9;
        for(int j=0; j<n; j++) ans = min(ans, dp[n-1][j]);
        return ans;
    }
};

/*TC: O(n²) — Computes the minimum falling path sum for each matrix cell once using tabulation.
SC: O(n²) — Uses a DP table of size n × n.*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int>prev(n,0);
        for(int j=0; j<n; j++) prev[j] = matrix[0][j];
        for(int i=1; i<n; i++){
            vector<int>curr(n,0);
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + prev[j];
                int leftD = 1e9;
                if(j - 1 >= 0) leftD = matrix[i][j] + prev[j-1];
                int rightD = 1e9;
                if(j + 1 < n) rightD = matrix[i][j] + prev[j+1];
                curr[j] = min({up, leftD, rightD});
            }
            prev = curr;
        }
        int ans = 1e9;
        for(int j=0; j<n; j++) ans = min(ans, prev[j]);
        return ans;
    }
};