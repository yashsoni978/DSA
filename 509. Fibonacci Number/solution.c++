class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }
};

/*TC: O(2ⁿ) — Each recursive call branches into two more calls, causing many overlapping computations.
SC: O(n) — Recursive call stack grows to a maximum depth of n.*/

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n <= 1) return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }

    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

/*TC: O(n) — Each Fibonacci number from 0 to n is computed only once and then reused.
SC: O(n) — O(n) for the memoization array and O(n) recursive call stack.*/

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        vector<int>dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++) dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    }
};

/*TC: O(n) — Computes each Fibonacci number once using bottom-up dynamic programming.
SC: O(n) — Uses a DP array of size n + 1 to store intermediate Fibonacci values.*/