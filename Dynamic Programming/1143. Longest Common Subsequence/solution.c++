class Solution {
private:
    int solve(int ind1, int ind2, string text1, string text2, vector<vector<int>>& dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2]) return dp[ind1][ind2] = 1 + solve(ind1-1, ind2-1, text1, text2, dp);
        return dp[ind1][ind2] = max(solve(ind1-1, ind2, text1, text2, dp), solve(ind1, ind2-1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(n-1, m-1, text1, text2, dp);
    }
};

/*TC: O(n × m) — Each (ind1, ind2) state is solved only once using memoization.
SC: O(n × m) — O(n × m) for the DP table and O(n + m) recursive call stack.*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int i=0; i<=m; i++) dp[0][i] = 0;
        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=1; ind2<=m; ind2++){
                if(text1[ind1 - 1] == text2[ind2 - 1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
            }
        }
        return dp[n][m];
    }
};

/*TC: O(n × m) — Computes each (ind1, ind2) state once using bottom-up dynamic programming.
SC: O(n × m) — Uses a DP table of size (n + 1) × (m + 1).*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int>prev(m+1,0);//base case is already intialiased by prev and curr to be 0
        for(int ind1=1; ind1<=n; ind1++){
            vector<int>curr(m+1,0);
            for(int ind2=1; ind2<=m; ind2++){
                if(text1[ind1 - 1] == text2[ind2 - 1]) curr[ind2] = 1 + prev[ind2-1];
                else curr[ind2] = max(prev[ind2], curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};