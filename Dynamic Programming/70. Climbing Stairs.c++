class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

class Solution {
private:
    int solve(int n, vector<int>& dp){
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return solve(n, dp);
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int>dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int prev2 = 1;
        int prev = 2;
        for(int i=3; i<=n; i++){
            int curr_i = prev + prev2;
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
    }
};