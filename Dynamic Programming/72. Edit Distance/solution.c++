class Solution {
private:
    int solve(int ind1, int ind2, string word1, string word2, vector<vector<int>>& dp){
        if(ind1 < 0) return ind2 + 1;
        if(ind2 < 0) return ind1 + 1;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(word1[ind1] == word2[ind2]) return dp[ind1][ind2] = solve(ind1-1, ind2-1, word1, word2, dp);
        return dp[ind1][ind2] = 1 + min(solve(ind1-1, ind2-1, word1, word2, dp), min(solve(ind1-1, ind2, word1, word2, dp), solve(ind1, ind2-1, word1, word2, dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};

/*TC: O(n × m) — Computes each (ind1, ind2) state once using memoization.
SC: O(n × m + n + m) — Uses an n × m DP table and O(n + m) recursion stack.*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;
        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=1; ind2<=m; ind2++){
                if(word1[ind1-1] == word2[ind2-1]) dp[ind1][ind2] = dp[ind1-1][ind2-1];
                else dp[ind1][ind2] = 1 + min(dp[ind1-1][ind2-1] , min(dp[ind1-1][ind2], dp[ind1][ind2-1]));
            }
        }
        return dp[n][m];
    }
};

/*TC: O(n × m) — Computes each (ind1, ind2) state once using bottom-up dynamic programming.
SC: O(n × m) — Uses a DP table of size (n + 1) × (m + 1).*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int>prev(m+1,0);
        for(int j=0; j<=m; j++) prev[j] = j;//But prev represents the row for ind1 = 0 (i.e., converting an empty word1 to prefixes of word2). "" -> ""    = 0 operations , "" -> "a"   = 1 insertion ,"" -> "ab"  = 2 insertions
        for(int ind1=1; ind1<=n; ind1++){
            vector<int>curr(m+1,0);
            curr[0] = ind1;//Because curr[0] means converting the first ind1 characters of word1 to an empty string.
            //"a"   -> "" = 1 deletion , "ab"  -> "" = 2 deletions , "abc" -> "" = 3 deletions
            for(int ind2=1; ind2<=m; ind2++){
                if(word1[ind1-1] == word2[ind2-1]) curr[ind2] = prev[ind2-1];
                else curr[ind2] = 1 + min(prev[ind2-1] , min(prev[ind2], curr[ind2-1]));
            }
            prev = curr;
        }
        return prev[m];
    }
};