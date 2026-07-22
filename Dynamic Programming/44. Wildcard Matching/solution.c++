class Solution {
private:
    bool isAllStars(string &s, int i){
        for(int j=0; j<=i; j++){
            if(s[j] != '*') return false;
        }
        return true;
    }
    bool solve(int i, int j, string &s, string &p, vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return isAllStars(p,j);   
        if(i >= 0 && j < 0) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == p[j] || p[j] == '?') dp[i][j] = solve(i-1, j-1, s, p, dp);
        else{
            if(p[j] == '*') dp[i][j] = solve(i-1, j, s, p, dp) || solve(i, j-1, s, p, dp);
            else dp[i][j] = false;
        }  
        return dp[i][j];
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>>dp(n, vector<int>(m,-1));
        return solve(n-1, m-1, s, p, dp);
    }
};

/*TC: O(n × m) — Computes each (i, j) state once using memoization.
SC: O(n × m + n + m) — Uses an n × m DP table and O(n + m) recursion stack.*/

class Solution {
private:
    bool isAllStars(string &p, int i){
        for(int j=0; j<=i; j++){
            if(p[j] != '*') return false;
        }
        return true;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1,false));
        dp[0][0] = true;
        for(int j=1; j<=m; j++) dp[0][j] = isAllStars(p, j-1);
        for(int i=1; i<=n; i++) dp[i][0] = false;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else{
                    if(p[j - 1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    else dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};
/*TC: O(n × m) — Computes each (text index, pattern index) state once using bottom-up dynamic programming.
SC: O(n × m) — Uses a DP table of size (n + 1) × (m + 1).*/

class Solution {
private:
    bool isAllStars(string &p, int i){
        for(int j=0; j<=i; j++){
            if(p[j] != '*') return false;
        }
        return true;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool>prev(m+1,false);
        prev[0] = true;
        for(int j=1; j<=m; j++) prev[j] = isAllStars(p, j-1);
        for(int i=1; i<=n; i++){
            vector<bool>curr(m+1,false);
            curr[0] = false;// = dp[i][0] => Does the first i characters of s match an empty pattern? ie s='a' and p = '' it doesnt match so return false;
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?') curr[j] = prev[j-1];
                else{
                    if(p[j - 1] == '*') curr[j] = prev[j] || curr[j-1];
                    else curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};