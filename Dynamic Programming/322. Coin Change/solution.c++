class Solution {
private:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notTake = solve(ind-1, amount, coins, dp);
        int take = 1e9;
        if(coins[ind] <= amount) take = 1 + solve(ind, amount - coins[ind], coins, dp);
        return dp[ind][amount] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        int ans = solve(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

/*TC: O(n × amount) — Each (index, amount) state is solved only once using memoization.
SC: O(n × amount) — O(n × amount) for the DP table and O(n) recursive call stack.*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,0));
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0) dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }
        for(int ind=1; ind<n; ind++){
            for(int target=0; target<=amount; target++){
                int notTake = dp[ind-1][target];
                int take = 1e9;
                if(coins[ind] <= target) take = 1 + dp[ind][target - coins[ind]];
                dp[ind][target] = min(take, notTake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};

/*TC: O(n × amount) — Computes each (index, amount) state once using bottom-up dynamic programming.
SC: O(n × amount) — Uses a DP table of size n × (amount + 1).*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0);
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0) prev[i] = i/coins[0];
            else prev[i] = 1e9;
        }
        for(int ind=1; ind<n; ind++){
            vector<int>curr(amount+1,0);
            for(int target=0; target<=amount; target++){
                int notTake = prev[target];
                int take = 1e9;
                if(coins[ind] <= target) take = 1 + curr[target - coins[ind]];
                curr[target] = min(take, notTake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};