class Solution {
private:
    int solve(int idx, int time, vector<int>& satisfaction, vector<vector<int>>& dp, int n){
        if(idx == n) return 0;
        if(dp[idx][time] != -1) return dp[idx][time];
        int take = satisfaction[idx] * time + solve(idx+1, time+1, satisfaction, dp, n);
        int notTake = solve(idx+1, time, satisfaction, dp, n);
        return dp[idx][time] = max(take, notTake); 
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return solve(0, 1, satisfaction, dp, n);   
    }
};

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>>dp(n+1, vector<int>(n+2,0));
        for(int idx=n-1; idx>=0; idx--){
            for(int time=n; time>=1; time--){
                int take = satisfaction[idx] * time + dp[idx+1][time+1];
                int notTake = dp[idx+1][time];
                dp[idx][time] = max(take, notTake);
            }
        }
        return dp[0][1];
    }
};

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int suffixSum = 0, ans = 0;
        for(int i=n-1; i>=0; i--){
            suffixSum += satisfaction[i];
            if(suffixSum > 0) ans += suffixSum;
            else break;
        }
        return ans;
    }
};