class Solution {
private:
    int solve(int ind, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind == n || cap == 0) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int ans = INT_MIN;
        if(buy == 1) ans = max(solve(ind+1, 1, cap, n, prices, dp), -prices[ind] + solve(ind+1, 0, cap, n, prices, dp));
        else ans = max(solve(ind+1, 0, cap, n, prices, dp), prices[ind] + solve(ind+1, 1, cap-1, n, prices, dp));
        return dp[ind][buy][cap] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return solve(0, 1, 2, n, prices, dp);
    }
};

/*TC: O(n) — There are n × 2 × 3 unique DP states, each computed once using memoization.
SC: O(n) — O(n × 2 × 3) DP table + O(n) recursion stack, which simplifies to O(n).*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){//cap = 0 in base case means all the states are already known so start with 1
                    int ans = INT_MIN;
                    if(buy == 1) ans = max(dp[ind+1][1][cap], -prices[ind] + dp[ind+1][0][cap]);
                    else ans = max(dp[ind+1][0][cap], prices[ind] + dp[ind+1][1][cap-1]);
                    dp[ind][buy][cap] = ans;
                }
            }
        }
        return dp[0][1][2];
    }
};

/*TC: O(n) — Fills n × 2 × 2 DP states once using bottom-up dynamic programming.
SC: O(n) — Uses a DP table of size (n + 1) × 2 × 3, which simplifies to O(n).*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>ahead(2, vector<int>(3,0));
        for(int ind=n-1; ind>=0; ind--){
            vector<vector<int>>curr(2, vector<int>(3,0));
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    int ans = INT_MIN;
                    if(buy == 1) ans = max(ahead[1][cap], -prices[ind] + ahead[0][cap]);
                    else ans = max(ahead[0][cap], prices[ind] + ahead[1][cap-1]);
                    curr[buy][cap] = ans;
                }
            }
            ahead = curr;
        }
        return ahead[1][2];
    }
};