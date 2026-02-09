class Solution {
private:
    int solve(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount % coins[0] == 0) return 1;//count ways's base case include one returning 0 and one returning one
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

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>>dp(n, vector<unsigned long long>(amount+1,0));
        for(int a = 0; a <= amount; a++){
            if(a % coins[0] == 0) dp[0][a] = 1;
            else dp[0][a] = 0; 
        }
        for(int ind=1; ind<n; ind++){
            for(int amt=0; amt<=amount; amt++){//must start from 0 because in cnt 0 will do contribution in answer while in max/min it doesnt neccessary contribute it so can start from 1 
                unsigned long long notTake = dp[ind-1][amt];
                unsigned long long take = 0;
                if(coins[ind] <= amt) take = dp[ind][amt - coins[ind]];
                dp[ind][amt] = take + notTake;
            }
        }
        return (int)dp[n-1][amount];
    }
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long>prev(amount+1,0);
        for(int a = 0; a <= amount; a++){
            if(a % coins[0] == 0) prev[a] = 1;
            else prev[a] = 0; 
        }
        for(int ind=1; ind<n; ind++){
            vector<unsigned long long>curr(amount+1,0);
            for(int amt=0; amt<=amount; amt++){//must start from 0 because in cnt 0 will do contribution in answer while in max/min it doesnt neccessary contribute it so can start from 1 
                unsigned long long notTake = prev[amt];
                unsigned long long take = 0;
                if(coins[ind] <= amt) take = curr[amt - coins[ind]];
                curr[amt] = take + notTake;
            }
            prev = curr;
        }
        return (int)prev[amount];
    }
};