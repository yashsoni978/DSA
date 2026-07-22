class Solution {
private:
    int solve(int ind, int prevInd, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == n) return 0;
        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        int notTake = solve(ind+1, prevInd, n, nums, dp);
        int take = 0;
        if(prevInd == -1 || nums[ind] > nums[prevInd]) take = 1 + solve(ind+1, ind, n, nums, dp);
        return dp[ind][prevInd+1] = max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));//ind = 0 -> n-1 but prev = -1 to n-1 -> shifting prev by +1
        return solve(0, -1, n, nums, dp); //prev = -1 at start
    }
};

/*TC: O(n²) — There are n × (n + 1) unique DP states, each computed once using memoization.
SC: O(n²) — O(n × (n + 1)) DP table + O(n) recursion stack, which simplifies to O(n²).*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        for(int ind=n-1; ind>=0; ind--){
            for(int prevInd=ind-1; prevInd>=-1; prevInd--){
                int notTake = dp[ind+1][prevInd+1];
                int take = 0;
                if(prevInd == -1 || nums[ind] > nums[prevInd]) take = 1 + dp[ind+1][ind+1];//This +1 is only because of the index shift used to represent prevInd = -1
                dp[ind][prevInd+1] = max(take, notTake);
            }
        }
        return dp[0][0];//-1 + 1
    }
};
/*TC: O(n²) — Fills all valid (ind, prevInd) DP states once using bottom-up tabulation.
SC: O(n²) — Uses a DP table of size (n + 1) × (n + 1).*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>ahead(n+1,0);
        for(int ind=n-1; ind>=0; ind--){
            vector<int>curr(n+1,0);
            for(int prevInd=ind-1; prevInd>=-1; prevInd--){
                int notTake = ahead[prevInd+1];
                int take = 0;
                if(prevInd == -1 || nums[ind] > nums[prevInd]) take = 1 + ahead[ind+1];//This +1 is only because of the index shift used to represent prevInd = -1
                curr[prevInd+1] = max(take, notTake);
            }
            ahead = curr;
        }
        return ahead[0];//-1 + 1
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[prev] < nums[i]) dp[i] = max(dp[i], 1 + dp[prev]);
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
