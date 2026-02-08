//n * target , sc - n * target + n(rss)
class Solution {
  private:
    bool solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        int n = arr.size();
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = solve(ind - 1, target, arr, dp);
        bool take = false;
        if(arr[ind] <= target) take = solve(ind - 1, target - arr[ind], arr, dp);
        return dp[ind][target] = take | notTake;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(sum+1,-1));
        return solve(n-1, sum, arr, dp);
    }
};

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1,false));
        for(int i=0; i<n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= sum; target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(arr[ind] <= target) take = dp[ind-1][target - arr[ind]];
                dp[ind][target] = take | notTake;
            }
        }
        return dp[n-1][sum];
    }
};

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<bool>prev(sum+1, false);
        prev[0] = true;
        prev[arr[0]] = true;
        for(int ind = 1; ind < n; ind++){
            vector<bool>curr(sum+1, false);
            curr[0] = true;
            for(int target = 1; target <= sum; target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target) take = prev[target - arr[ind]];
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
};