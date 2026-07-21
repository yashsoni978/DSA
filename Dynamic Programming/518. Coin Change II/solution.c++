class Solution {
private:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount % coins[0] == 0) return 1;
            else return 0;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notTake = solve(ind-1, amount, coins, dp);
        int take = 0;
        if(coins[ind] <= amount) take = solve(ind, amount - coins[ind], coins, dp);
        return dp[ind][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));
        return solve(n-1, amount, coins, dp);
    }
};

/*TC: O(n × amount) — Each (index, amount) state is solved only once using memoization to count all possible combinations.
SC: O(n × amount) — O(n × amount) for the DP table and O(n) recursive call stack.*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>>dp(n, vector<unsigned long long>(amount+1,0));
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0) dp[0][i] = 1;
            else dp[0][i] = 0;
        }
        for(int ind=1; ind<n; ind++){
            for(int target=0; target<=amount; target++){
                unsigned long long notTake = dp[ind-1][target];
                unsigned long long take = 0;
                if(coins[ind] <= target) take = dp[ind][target - coins[ind]];
                dp[ind][target] = take + notTake;
            }
        }
        return (int)dp[n-1][amount];
    }
};

/*TC: O(n × amount) — Computes each (index, amount) state once using bottom-up dynamic programming to count all possible combinations.
SC: O(n × amount) — Uses a DP table of size n × (amount + 1).*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long>prev(amount+1,0);
        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0) prev[i] = 1;
            else prev[i] = 0;
        }
        for(int ind=1; ind<n; ind++){
            vector<unsigned long long>curr(amount+1,0);
            for(int target=0; target<=amount; target++){
                unsigned long long notTake = prev[target];
                unsigned long long take = 0;
                if(coins[ind] <= target) take = curr[target - coins[ind]];
                curr[target] = take + notTake;
            }
            prev = curr;
        }
        return (int)prev[amount];
    }
};