class Solution {
  private:
    int solve(int ind, int N, vector<int>& price, vector<vector<int>>& dp){
        if(ind == 0) return N*price[0];
        if(dp[ind][N] != -1) return dp[ind][N];
        int notTake = solve(ind - 1, N, price, dp);
        int rodLength = ind + 1;
        int take = INT_MIN;
        if(rodLength <= N) take = price[ind] + solve(ind, N - rodLength, price, dp);
        return dp[ind][N] = max(take, notTake);
    }
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));;
        return solve(n-1, n, price, dp);
    }
};

/*TC: O(n²) — Each (index, remaining rod length) state is solved only once using memoization.
SC: O(n²) — O(n × (n + 1)) for the DP table and O(n) recursive call stack.*/


class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n, vector<int>(n+1,0));
        for(int i=0; i<=n; i++) dp[0][i] = i * price[0];
        for(int ind=1; ind<n; ind++){
            for(int N=0; N<=n; N++){
                int notTake = dp[ind-1][N];
                int rodLength = ind + 1;
                int take = INT_MIN;
                if(rodLength <= N) take = price[ind] + dp[ind][N - rodLength];
                dp[ind][N] = max(take, notTake);
            }
        }
        return dp[n-1][n];
    }
};

/*TC: O(n²) — Computes each (index, remaining rod length) state once using bottom-up dynamic programming.
SC: O(n²) — Uses a DP table of size n × (n + 1).*/

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int>prev(n+1,0);
        for(int i=0; i<=n; i++) prev[i] = i * price[0];
        for(int ind=1; ind<n; ind++){
            vector<int>curr(n+1,0);
            for(int N=0; N<=n; N++){
                int notTake = prev[N];
                int rodLength = ind + 1;
                int take = INT_MIN;
                if(rodLength <= N) take = price[ind] + curr[N - rodLength];
                curr[N] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[n];
    }
};

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int>prev(n+1,0);
        for(int i=0; i<=n; i++) prev[i] = i * price[0];
        for(int ind=1; ind<n; ind++){
            for(int N=0; N<=n; N++){
                int notTake = prev[N];
                int rodLength = ind + 1;
                int take = INT_MIN;
                if(rodLength <= N) take = price[ind] + prev[N - rodLength];
                prev[N] = max(take, notTake);
            }
        }
        return prev[n];
    }
};