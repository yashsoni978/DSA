class Solution {
private:
    int solve(int ind, int buy, int n, vector<int>& prices, vector<vector<int>>& dp){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int ans = INT_MIN;
        //going to buy
        if(buy == 1) ans = max(solve(ind+1, 1, n, prices, dp), -prices[ind] + solve(ind+1, 0, n, prices, dp));
        else ans = max(solve(ind+1, 0, n, prices, dp), prices[ind] + solve(ind+1, 1, n, prices, dp));
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
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                int ans = INT_MIN;
                if(buy == 1) ans = max(dp[ind+1][1], -prices[ind] + dp[ind+1][0]);
                else ans = max(dp[ind+1][0], prices[ind] + dp[ind+1][1]);
                dp[ind][buy] = ans;
            }
        }
        return dp[0][1];
    }
};

/*TC: O(n) — Fills n × 2 DP states once using bottom-up tabulation.
SC: O(n) — Uses a DP table of size (n + 1) × 2, which simplifies to O(n).*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>ahead(2,0);
        ahead[0] = ahead[1] = 0;
        for(int ind=n-1; ind>=0; ind--){
            vector<int>curr(2,0);
            for(int buy=0; buy<=1; buy++){
                int ans = INT_MIN;
                if(buy == 1) ans = max(ahead[1], -prices[ind] + ahead[0]);
                else ans = max(ahead[0], prices[ind] + ahead[1]);
                curr[buy] = ans;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};