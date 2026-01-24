class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int i=1; i*i <= n; i++){
            ans = min(ans, 1 + solve(n - i*i, dp));
        }
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n, dp);
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,1e9);
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j*j <= i; j++){
                int remain = i - j*j;
                dp[i] = min(dp[i], 1 + dp[remain]); 
            }
        }
        return dp[n];
    }
};