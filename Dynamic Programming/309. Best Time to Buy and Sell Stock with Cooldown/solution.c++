class Solution {
private:
    int solve(int ind, int buy, int n, vector<int>& prices, vector<vector<int>>& dp){
        if(ind >= n) return 0;//out of bounds
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int ans = INT_MIN;
        //going to buy
        if(buy == 1) ans = max(solve(ind+1, 1, n, prices, dp), -prices[ind] + solve(ind+1, 0, n, prices, dp));
        else ans = max(solve(ind+1, 0, n, prices, dp), prices[ind] + solve(ind+2, 1, n, prices, dp));
        return dp[ind][buy] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return solve(0, 1, n, prices, dp);//initially allowed to buy
    }
};

/*TC: O(n) — There are n × 2 unique DP states, each computed once using memoization.
SC: O(n) — O(n × 2) DP table + O(n) recursion stack, which simplifies to O(n).*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2,0));//n+2 to get rid of out of bound
        dp[n][0] = dp[n][1] = 0;
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                int ans = INT_MIN;
                if(buy == 1) ans = max(dp[ind+1][1], -prices[ind] + dp[ind+1][0]);
                else ans = max(dp[ind+1][0], prices[ind] + dp[ind+2][1]);
                dp[ind][buy] = ans;
            }
        }
        return dp[0][1];
    }
};