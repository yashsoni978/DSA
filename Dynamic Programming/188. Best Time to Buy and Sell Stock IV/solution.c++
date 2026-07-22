class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1,0)));//at last we will access k
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){//cap = 0 in base case means all the states are already known so start with 1
                    int ans = INT_MIN;
                    if(buy == 1) ans = max(dp[ind+1][1][cap], -prices[ind] + dp[ind+1][0][cap]);
                    else ans = max(dp[ind+1][0][cap], prices[ind] + dp[ind+1][1][cap-1]);
                    dp[ind][buy][cap] = ans;
                }
            }
        }
        return dp[0][1][k];
    }
};

/*TC: O(n × k) — Fills n × 2 × k DP states once using bottom-up dynamic programming.
SC: O(n × k) — Uses a DP table of size (n + 1) × 2 × (k + 1).*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>ahead(2, vector<int>(k+1,0));
        for(int ind=n-1; ind>=0; ind--){
            vector<vector<int>>curr(2, vector<int>(k+1,0));
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    int ans = INT_MIN;
                    if(buy == 1) ans = max(ahead[1][cap], -prices[ind] + ahead[0][cap]);
                    else ans = max(ahead[0][cap], prices[ind] + ahead[1][cap-1]);
                    curr[buy][cap] = ans;
                }
            }
            ahead = curr;
        }
        return ahead[1][k];
    }
};

/*TC: O(n × k) — Computes each day, buy state, and transaction count once using space-optimized DP.
SC: O(k) — Uses two arrays of size 2 × (k + 1), reducing space from O(n × k) to O(k).*/