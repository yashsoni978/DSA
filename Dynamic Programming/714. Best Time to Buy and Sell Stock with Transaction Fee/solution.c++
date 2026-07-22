class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>ahead(2,0);
        ahead[0] = ahead[1] = 0;
        for(int ind=n-1; ind>=0; ind--){
            vector<int>curr(2,0);
            for(int buy=0; buy<=1; buy++){
                int ans = INT_MIN;
                if(buy == 1) ans = max(ahead[1], -prices[ind] + ahead[0]);
                else ans = max(ahead[0], prices[ind] - fee + ahead[1]);
                curr[buy] = ans;
            }
            ahead = curr;
        }
        return ahead[1];
    }
};