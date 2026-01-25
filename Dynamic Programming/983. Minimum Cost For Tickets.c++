class Solution {
private:
    int solve(int idx, vector<int>& days, vector<int>& costs, vector<int>& dp, int n){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int cost1 = costs[0] + solve(idx+1, days, costs, dp, n);
        int i = idx;
        while(i < n && days[i] < days[idx] + 7) i++;
        int cost7 = costs[1] + solve(i, days, costs, dp, n);
        i = idx;
        while(i < n && days[i] < days[idx] + 30) i++;
        int cost30 = costs[2] + solve(i, days, costs, dp, n);
        return dp[idx] = min({cost1, cost7, cost30});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n,-1);
        return solve(0, days, costs, dp, n);
    }
};

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n+1,0);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            int cost1 = costs[0] + dp[i+1];
            int j = i;
            while(j < n && days[j] < days[i] + 7) j++;
            int cost7 = costs[1] + dp[j];
            j = i;
            while(j < n && days[j] < days[i] + 30) j++;
            int cost30 = costs[2] + dp[j];
            dp[i] = min({cost1, cost7, cost30});
        }
        return dp[0];
    }
};