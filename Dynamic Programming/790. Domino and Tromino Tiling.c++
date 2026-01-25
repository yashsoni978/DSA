class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        if(dp[n] != -1) return dp[n];
        int MOD = 1e9 + 7;
        return dp[n] = (2LL * solve(n-1, dp) % MOD + solve(n-3, dp) % MOD) % MOD;
    }
public:
    int numTilings(int n) {
        vector<int>dp(n+1,-1);
        return solve(n, dp);
    }
};

class Solution {
public:
    int numTilings(int n) {
        int MOD = 1e9 + 7;
        vector<long long>dp(n+1,0);
        if(n <= 2) return n;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i=4; i<=n; i++){
            dp[i] = (2LL*dp[i-1] % MOD + dp[i-3] % MOD) % MOD;
        }
        return dp[n];
    }
};