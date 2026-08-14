class Solution {
private:
    int solve(int ind1, int ind2, string &word1, string &word2, vector<vector<int>>& dp){
        if(ind1 < 0) return ind2+1;
        if(ind2 < 0) return ind1+1;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(word1[ind1] == word2[ind2]) return dp[ind1][ind2] = solve(ind1-1, ind2-1, word1, word2, dp);
        else return dp[ind1][ind2] = 1 + min(solve(ind1-1, ind2, word1, word2, dp), solve(ind1, ind2-1, word1, word2, dp));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int>prev(m+1,0);
        for(int j=0; j<=m; j++) prev[j] = j;
        for(int i=1; i<=n; i++){
            vector<int>curr(m+1,0);
            curr[0] = i;
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
                else curr[j] = 1 + min(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};