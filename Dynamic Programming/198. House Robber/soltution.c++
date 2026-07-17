class Solution {
private:
    int solve(int ind, vector<int>& nums, vector<int>& dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + solve(ind-2, nums, dp);
        int notPick = solve(ind-1, nums, dp);
        return dp[ind] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(n-1, nums, dp);
    }
};  

/*TC: O(n) — Each house (index) is computed only once using memoization.
SC: O(n) — O(n) for the DP array and O(n) recursive call stack.*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i > 1) pick += dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }
};

/*TC: O(n) — Computes the maximum money for each house once using bottom-up DP.
SC: O(n) — Uses a DP array of size n to store the maximum profit up to each house.*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0], prev2 = 0;
        for(int i=1; i<n; i++){
            int pick = nums[i];
            if(i > 1) pick += prev2;
            int notPick = prev;
            int curr = INT_MIN;
            curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};