class Solution {
  private:
    int solve(int ind, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if(ind == 0) return (capacity/wt[0]) * val[0];
        if(dp[ind][capacity] != -1) return dp[ind][capacity];
        int notTake = solve(ind - 1, capacity, val, wt, dp);
        int take = INT_MIN;
        if(wt[ind] <= capacity) take = val[ind] + solve(ind, capacity - wt[ind], val, wt, dp);
        return dp[ind][capacity] = max(take, notTake);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(capacity+1,-1));
        return solve(n-1, capacity, val, wt, dp);
    }
};

/*TC: O(n × capacity) — Each (index, capacity) state is solved only once using memoization.
SC: O(n × capacity) — O(n × capacity) for the DP table and O(n) recursive call stack.*/

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(capacity+1,0));
        for(int i = 0; i <= capacity; i++) dp[0][i] = (i / wt[0]) * val[0];
        for(int ind=1; ind<n; ind++){
            for(int W=0; W<=capacity; W++){
                int notTake = dp[ind - 1][W];
                int take = INT_MIN;
                if(wt[ind] <= W) take = val[ind] + dp[ind][W - wt[ind]];
                dp[ind][W] = max(take, notTake);
            }
        }
        return dp[n-1][capacity];
    }
};

/*TC: O(n × capacity) — Computes each (index, capacity) state once using bottom-up dynamic programming.
SC: O(n × capacity) — Uses a DP table of size n × (capacity + 1).*/

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<int>prev(capacity+1,0);
        for(int i = 0; i <= capacity; i++) prev[i] = (i / wt[0]) * val[0];
        for(int ind=1; ind<n; ind++){
            vector<int>curr(capacity+1,0);
            for(int W=0; W<=capacity; W++){
                int notTake = prev[W];
                int take = INT_MIN;
                if(wt[ind] <= W) take = val[ind] + curr[W - wt[ind]];
                curr[W] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[capacity];
    }
};

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<int>prev(capacity+1,0);
        for(int i = 0; i <= capacity; i++) prev[i] = (i / wt[0]) * val[0];
        for(int ind=1; ind<n; ind++){
            for(int W=0; W<=capacity; W++){
                int notTake = prev[W];
                int take = INT_MIN;
                if(wt[ind] <= W) take = val[ind] + prev[W - wt[ind]];
                prev[W] = max(take, notTake);
            }
        }
        return prev[capacity];
    }
};