//tc - n * w
//sc - n * w + n(rss)
class Solution {
  private:
    int solve(int ind, int w, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if(ind == 0){
            if(wt[0] <= w) return val[0];
            else return 0;
        }
        if(dp[ind][w] != -1) return dp[ind][w];
        int notTake = solve(ind - 1, w, val, wt, dp);
        int take = INT_MIN;
        if(wt[ind] <= w) take = val[ind] + solve(ind-1, w - wt[ind], val, wt, dp);
        return dp[ind][w] = max(take, notTake);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n, vector<int>(W+1,-1));
        return solve(n-1, W, val, wt, dp);
    }
};

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n, vector<int>(W+1,0));
        for(int i=wt[0]; i<=W; i++) dp[0][i] = val[0];
        for(int ind=1; ind < n; ind++){
            for(int weight=1; weight<=W; weight++){
                int notTake = dp[ind-1][weight];
                int take = INT_MIN;
                if(wt[ind] <= weight) take = val[ind] + dp[ind-1][weight - wt[ind]];
                dp[ind][weight] = max(take,notTake);
            }
        }
        return dp[n-1][W];
    }
};

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<int>prev(W+1,0);
        for(int i=wt[0]; i<=W; i++) prev[i] = val[0];
        for(int ind=1; ind < n; ind++){
            vector<int>curr(W+1,0);
            for(int weight=1; weight<=W; weight++){
                int notTake = prev[weight];
                int take = INT_MIN;
                if(wt[ind] <= weight) take = val[ind] + prev[weight - wt[ind]];
                curr[weight] = max(take,notTake);
            }
            prev = curr;
        }
        return prev[W];
    }
};