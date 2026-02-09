class Solution {
private:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount % coins[0] == 0) return amount/coins[0];//if the last coin is divisible by target then only we can take that last coin
            else return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notTake = solve(ind-1, amount, coins, dp);
        int take = 1e9;
        if(coins[ind] <= amount) take = 1 + solve(ind, amount - coins[ind], coins, dp);//here we are counting the no of coins so add 1
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

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1,0));
        for(int a = 0; a <= amount; a++){
            if(a % coins[0] == 0) dp[0][a] = a / coins[0];
            else dp[0][a] = 1e9; 
        }
        for(int ind=1; ind<n; ind++){
            for(int amt=1; amt<=amount; amt++){
                int notTake = dp[ind-1][amt];
                int take = 1e9;
                if(coins[ind] <= amt) take = 1 + dp[ind][amt - coins[ind]];
                dp[ind][amt] = min(take, notTake);
            }
        }
        int ans = dp[n-1][amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>prev(amount+1,0);
        for(int a = 0; a <= amount; a++){
            if(a % coins[0] == 0) prev[a] = a / coins[0];
            else prev[a] = 1e9; 
        }
        for(int ind=1; ind<n; ind++){
            vector<int>curr(amount+1,0);
            for(int amt=1; amt<=amount; amt++){
                int notTake = prev[amt];
                int take = 1e9;
                if(coins[ind] <= amt) take = 1 + curr[amt - coins[ind]];
                curr[amt] = min(take, notTake);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};