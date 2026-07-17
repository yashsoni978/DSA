class Solution {
  private:
    int solve(int ind, vector<int>& height, vector<int>& dp){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int jumpOne = solve(ind-1, height, dp) + abs(height[ind] - height[ind-1]);
        int jumpTwo = INT_MAX;
        if(ind > 1) jumpTwo = solve(ind - 2, height, dp) + abs(height[ind] - height[ind-2]);
        return min(jumpOne, jumpTwo);
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n,-1);
        return solve(n-1, height, dp);
    }
};

/*TC: O(n) — Each state (index) is computed only once using memoization.
SC: O(n) — O(n) for the DP array and O(n) recursive call stack.*/

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n,0);
        dp[0] = 0;
        for(int ind=1; ind<n; ind++){
            int jumpOne = dp[ind-1] + abs(height[ind] - height[ind-1]);
            int jumpTwo = INT_MAX;
            if(ind > 1) jumpTwo = dp[ind - 2] + abs(height[ind] - height[ind - 2]);
            dp[ind] = min(jumpOne, jumpTwo);
        }
        return dp[n-1];
    }
};

/*TC: O(n) — Computes the minimum cost for each stair once using tabulation.
SC: O(n) — Uses a DP array of size n to store the minimum cost for each stair.*/

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        int prev = 0, prev2 = 0;
        for(int ind=1; ind<n; ind++){
            int jumpOne = prev + abs(height[ind] - height[ind-1]);
            int jumpTwo = INT_MAX;
            if(ind > 1) jumpTwo = prev2 + abs(height[ind] - height[ind - 2]);
            int curr = INT_MAX;
            curr = min(jumpOne, jumpTwo);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

/*TC: O(n) — Computes the minimum cost for each stair once using space-optimized DP.
SC: O(1) — Uses only constant extra space by storing the previous two DP states.*/