class Solution {
private:
    int solve(int ind1, int ind2, string s, string t, vector<vector<int>>& dp){
        int MOD = 1e9 + 7;
        if(ind2 < 0) return 1;
        if(ind1 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int res = 0;
        if(s[ind1] == t[ind2]){
            int leave = solve(ind1 - 1, ind2 - 1, s, t, dp);
            int stay = solve(ind1 - 1, ind2, s, t, dp);
            res = (leave + stay) % MOD;
        }
        else res = solve(ind1-1, ind2, s, t, dp);
        return dp[ind1][ind2] = res;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(n-1, m-1, s, t, dp);
    }
};

/*TC: O(n × m) — Computes each (ind1, ind2) state once using memoization.
SC: O(n × m + n) — Uses an n × m DP table and O(n) recursion stack.*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        int MOD = 1e9 + 7;
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;//No need of second base case because of dp initialisation
        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=1; ind2<=m; ind2++){
                if(s[ind1-1] == t[ind2-1]) dp[ind1][ind2] = (dp[ind1-1][ind2-1] + dp[ind1-1][ind2]) % MOD;
                else dp[ind1][ind2] = dp[ind1-1][ind2];
            }
        }
        return dp[n][m];
    }
};

/*TC: O(n × m) — Computes each (ind1, ind2) state once using tabulation.
SC: O(n × m) — Uses a DP table of size (n + 1) × (m + 1).*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        int MOD = 1e9 + 7;
        vector<int>prev(m+1,0);
        prev[0] = 1;
        for(int ind1=1; ind1<=n; ind1++){
            vector<int>curr(m+1,0);
            curr[0] = 1;
            for(int ind2=1; ind2<=m; ind2++){
                if(s[ind1-1] == t[ind2-1]) curr[ind2] = (prev[ind2-1] + prev[ind2]) % MOD;
                else curr[ind2] = prev[ind2];
            }
            prev = curr;
        }
        return prev[m];
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        int MOD = 1e9 + 7;
        vector<int>prev(m+1,0);
        prev[0] = 1;
        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=m; ind2>=1; ind2--){
                if(s[ind1-1] == t[ind2-1]) prev[ind2] = (prev[ind2-1] + prev[ind2]) % MOD;
            }
        }
        return prev[m];
    }
};