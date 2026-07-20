class Solution {
  private:
    int solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(ind == 0){
            if(arr[0] == 0 && target == 0) return 2;
            if(target == 0 || arr[0] == target) return 1;
            else return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = solve(ind - 1, target, arr, dp);
        int take = 0;
        if(arr[ind] <= target) take = solve(ind - 1, target - arr[ind], arr, dp);
        return dp[ind][target] = take + notTake;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(target+1,-1));
        return solve(n-1, target, arr, dp);
    }
};

/*TC: O(n × target) — Each (index, target) state is computed only once using memoization to count all valid subsets.
SC: O(n × target) — O(n × target) for the DP table and O(n) recursive call stack.*/

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(target+1,0));
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
        for(int ind=1; ind<n; ind++){
            for(int t=0; t<=target; t++){
                int notTake = dp[ind-1][t];
                int take = 0;
                if(arr[ind] <= t) take = dp[ind-1][t - arr[ind]];
                dp[ind][t] = take + notTake;
            }
        }
        return dp[n-1][target];
    }
};

/*TC: O(n × target) — Computes each (index, target) state once using bottom-up dynamic programming to count all valid subsets.
SC: O(n × target) — Uses a DP table of size n × (target + 1).*/

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<int>prev(target+1,0);
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;
        for(int ind=1; ind<n; ind++){
            vector<int>curr(target+1,0);
            for(int t=0; t<=target; t++){
                int notTake = prev[t];
                int take = 0;
                if(arr[ind] <= t) take = prev[t - arr[ind]];
                curr[t] = take + notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
};