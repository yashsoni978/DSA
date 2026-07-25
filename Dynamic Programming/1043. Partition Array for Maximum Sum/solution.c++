class Solution {
private:
    int solve(int i, vector<int>& arr, int k, int n, vector<int>& dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxi = 0, ans = 0, len = 0;
        for(int j=i; j<min(n,i+k); j++){
            len++;
            maxi = max(maxi, arr[j]);
            int sum = maxi * len + solve(j+1, arr, k, n, dp);
            ans = max(ans, sum);
        }
        return dp[i] = ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return solve(0, arr, k, n, dp);
    }
};

/*TC = O(n × k), SC = O(n) + O(n). Each index is solved once and tries at most k partition lengths.*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            int maxi = 0, ans = 0, len = 0;
            for(int j=i; j<min(n,i+k); j++){
                len++;
                maxi = max(maxi, arr[j]);
                int sum = maxi * len + dp[j+1];
                ans = max(ans, sum);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};

/*TC = O(n × k), SC = O(n). Uses a 1D DP array and computes states from right to left.*/