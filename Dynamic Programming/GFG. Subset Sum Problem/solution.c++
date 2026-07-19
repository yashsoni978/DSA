class Solution {
  private:
    bool check(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = check(ind-1, target, arr, dp);
        bool take = false;
        if(arr[ind] <= target) take = check(ind-1, target - arr[ind], arr, dp);
        return dp[ind][target] = take || notTake;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return check(n-1, sum, arr, dp);
    }
};

/*TC: O(n × sum) — Each (index, target) state is solved only once using memoization.
SC: O(n × sum) — O(n × sum) for the DP table and O(n) recursive call stack.*/

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1,false));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if(arr[0] <= sum) dp[0][arr[0]] = true;
        for(int ind=1; ind<n; ind++){
            for(int target=1; target<=sum; target++){
                bool notTake = dp[ind-1][target];;
                bool take = false;
                if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];
                dp[ind][target] = take || notTake;
            }
        }
        return dp[n-1][sum];
    }
};

/*TC: O(n × sum) — Computes each (index, target) state once using bottom-up dynamic programming.
SC: O(n × sum) — Uses a DP table of size n × (sum + 1).*/

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<bool>prev(sum+1, false);
        prev[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;
        for(int ind=1; ind<n; ind++){
            vector<bool>curr(sum+1, false);
            curr[0] = true;
            for(int target=1; target<=sum; target++){
                bool notTake = prev[target];;
                bool take = false;
                if(arr[ind] <= target) take = prev[target - arr[ind]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

/*TC: O(n × sum) — Computes each (index, target) state once using space-optimized dynamic programming.
SC: O(sum) — Uses two 1D arrays of size (sum + 1) instead of a 2D DP table.*/
