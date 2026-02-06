class Solution {
  private:
    int solve(int ind, vector<int>& height, vector<int>& dp){
        if(ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int climb1 = abs(height[ind] - height[ind-1]) + solve(ind-1, height, dp);
        int climb2 = INT_MAX;
        if(ind > 1) climb2 = abs(height[ind] - height[ind-2]) + solve(ind-2, height, dp);
        return dp[ind] = min(climb1, climb2);
    }
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n,-1);
        return solve(n-1, height, dp);
    }
};

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int>dp(n, 0);
        dp[0] = 0;
        for(int i=1; i<n; i++){
            int climb1 = abs(height[i] - height[i-1]) + dp[i-1];
            int climb2 = INT_MAX;
            if(i > 1) climb2 = abs(height[i] - height[i-2]) + dp[i-2];
            dp[i] = min(climb1, climb2);
        }
        return dp[n-1];
    }
};

class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        int prev2 = 0, prev = 0;
        for(int i=1; i<n; i++){
            int climb1 = abs(height[i] - height[i-1]) + prev;
            int climb2 = INT_MAX;
            if(i > 1) climb2 = abs(height[i] - height[i-2]) + prev2;
            int curr_i = min(climb1, climb2);
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
    }
};