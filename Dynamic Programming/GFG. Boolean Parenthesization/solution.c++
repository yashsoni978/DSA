class Solution {
  private:
    int solve(int i, int j, int isTrue, string &s, vector<vector<vector<int>>>& dp){
        if(i > j) return 0;
        if(i == j){
            if(isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        int ways = 0;
        for(int k=i+1; k<=j-1; k+=2){
            int LT = solve(i, k-1, 1, s, dp);
            int LF = solve(i, k-1, 0, s, dp);
            int RT = solve(k+1, j, 1, s, dp);
            int RF = solve(k+1, j, 0, s, dp);
            if(s[k] == '&'){
                if(isTrue) ways += LT * RT;
                else ways += LT * RF + LF * RT + LF * RF;
            }
            else if(s[k] == '|'){
                if(isTrue) ways += LT * RT + LT * RF + LF * RT;
                else ways += LF * RF;
            }
            else{
                if(isTrue) ways += LT * RF + LF * RT;
                else ways += LT * RT + LF * RF;
            }
        }
        return dp[i][j][isTrue] = ways;
    }
  public:
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2,-1)));
        return solve(0, n-1, 1, s, dp);
    }
};  

/*TC: O(n³)
SC: O(n² × 2) + O(n)
There are O(n² × 2) DP states (i, j, isTrue).
Each state tries O(n) partition points.
Recursion depth is O(n).*/

class Solution {
  public:
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2,0)));
        for(int i=0; i<n; i+=2){
            dp[i][i][1] = (s[i] == 'T');
            dp[i][i][0] = (s[i] == 'F');
        }
        for(int i=n-1; i>=0; i-=2){
            for(int j=0; j<n; j+=2){
                if(i > j) continue;
                if(i == j) continue;
                for(int isTrue = 0; isTrue <= 1; isTrue++){
                    int ways = 0;
                    for(int k=i+1; k<=j-1; k+=2){
                        int LT = dp[i][k-1][1];
                        int LF = dp[i][k-1][0];
                        int RT = dp[k+1][j][1];
                        int RF = dp[k+1][j][0];
                        if(s[k] == '&'){
                            if(isTrue) ways += LT * RT;
                            else ways += LT * RF + LF * RT + LF * RF;
                        }
                        else if(s[k] == '|'){
                            if(isTrue) ways += LT * RT + LT * RF + LF * RT;
                            else ways += LF * RF;
                        }
                        else{
                            if(isTrue) ways += LT * RF + LF * RT;
                            else ways += LT * RT + LF * RF;
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }
        return dp[0][n-1][1];
    }
};

/*TC = O(n³), SC = O(n² × 2) using a 3D DP table with no recursion stack.*/