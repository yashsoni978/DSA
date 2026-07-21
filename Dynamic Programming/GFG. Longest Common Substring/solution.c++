class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n = s1.size(), m = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,0));
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int i=0; i<=m; i++) dp[0][i] = 0;
        int ans = 0;
        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=1; ind2<=m; ind2++){
                int val = 0;
                if(s1[ind1 - 1] == s2[ind2 - 1]){
                    val = 1 + dp[ind1-1][ind2-1];
                    dp[ind1][ind2] = val;
                    ans = max(ans, val);
                }
                else dp[ind1][ind2] = 0;
            }
        }
        return ans;
    }
};

/*TC: O(n × m) — Computes the length of the common substring ending at each pair of indices once using tabulation.
SC: O(n × m) — Uses a DP table of size (n + 1) × (m + 1).*/