class Solution {
  private:
    int solve(int ind, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(ind == 0){
            if(target == 0 && arr[0] == 0) return 2; //pick and not pick
            if(target == 0 || arr[0] == target) return 1; //notPick only or pick only
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int take = 0;
        if(arr[ind] <= target) take = solve(ind - 1, target - arr[ind], arr, dp);
        int notTake = solve(ind-1, target, arr, dp);
        return take + notTake;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return solve(n-1, target, arr, dp);
    }
};

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(target+1,0));
        if(arr[0] == 0) dp[0][0] = 2; //Case 1 : pick and notPick
        //Case 2 : arr[0] != 0
        //if it is equal to <= target we can pick it 
        //else we will not pick
        else dp[0][0] = 1;//notPick
        if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;//pick
        for(int ind = 1; ind < n; ind++){
            for(int tar=0; tar<=target; tar++){//have to take it from 0 as questions says elements can start from 0
                int notTake = dp[ind-1][tar];
                int take = 0;
                if(arr[ind] <= tar) take = dp[ind-1][tar - arr[ind]];
                dp[ind][tar] = take + notTake;
            }
        }
        return dp[n-1][target];
    }
};

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<int>prev(target+1,0);
        if(arr[0] == 0) prev[0] = 2; //Case 1 : pick and notPick
        //Case 2 : arr[0] != 0
        //if it is equal to <= target we can pick it 
        //else we will not pick
        else prev[0] = 1;//notPick
        if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;//pick
        for(int ind = 1; ind < n; ind++){
            vector<int>curr(target+1,0);
            for(int tar=0; tar<=target; tar++){//have to take it from 0 as questions says elements can start from 0
                int notTake = prev[tar];
                int take = 0;
                if(arr[ind] <= tar) take = prev[tar - arr[ind]];
                curr[tar] = take + notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
};