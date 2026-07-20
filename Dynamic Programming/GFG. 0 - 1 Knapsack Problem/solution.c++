class Solution {
  private:
    int solve(int ind, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if(ind == 0){
            if(wt[0] <= W) return val[0];
            else return 0;
        }
        if(dp[ind][W] != -1) return dp[ind][W];
        int notTake = solve(ind-1, W, val, wt, dp);
        int take = INT_MIN;
        if(wt[ind] <= W) take = val[ind] + solve(ind-1, W - wt[ind], val, wt, dp);
        return max(take, notTake);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(W+1,-1));
        return solve(n-1, W, val, wt, dp);
    }
};

/*TC: O(n × W) — Each (index, capacity) state is solved only once using memoization.
SC: O(n × W) — O(n × W) for the DP table and O(n) recursive call stack.*/

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(W+1,0));
        for(int i=wt[0]; i<=W; i++) dp[0][i] = val[0];
        for(int ind=1; ind<n; ind++){
            for(int weight=0; weight<=W; weight++){
                int notTake = dp[ind-1][weight];
                int take = INT_MIN;
                if(wt[ind] <= weight) take = val[ind] + dp[ind-1][weight - wt[ind]];
                dp[ind][weight] = max(take, notTake);
            }
        }
        return dp[n-1][W];
    }
};

/*TC: O(n × W) — Computes each (index, capacity) state once using bottom-up dynamic programming.
SC: O(n × W) — Uses a DP table of size n × (W + 1).*/

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<int>prev(W+1,0);
        for(int i=wt[0]; i<=W; i++) prev[i] = val[0];
        for(int ind=1; ind<n; ind++){
            for(int weight=W; weight>=0; weight--){
                int notTake = prev[weight];
                int take = INT_MIN;
                if(wt[ind] <= weight) take = val[ind] + prev[weight - wt[ind]];
                prev[weight] = max(take, notTake);
            }
        }
        return prev[W];
    }
};