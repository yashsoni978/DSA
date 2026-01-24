class Solution {
private:
    int solve(int idx, int day, vector<int>& jobDifficulty, int n, vector<vector<int>>& dp){
        if(day == 1){
            int maxi = INT_MIN;
            for(int i=idx; i<n; i++) maxi = max(maxi, jobDifficulty[i]);
            return maxi;
        }
        if(dp[idx][day] != -1) return dp[idx][day];
        int res = INT_MAX, maxi = INT_MIN;
        for(int i=idx; i<=n-day; i++){
            maxi = max(maxi, jobDifficulty[i]);
            int next = solve(i+1, day-1, jobDifficulty, n, dp);
            res = min(res, maxi + next);
        }
        return dp[idx][day] = res;
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int>>dp(n, vector<int>(d+1,-1));
        return solve(0, d, jobDifficulty, n, dp);
    }
};

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int>>dp(n, vector<int>(d+1, 0));
        for(int i=0; i<n; i++){
            int maxi = INT_MIN;
            for(int j=i; j<n; j++) maxi = max(maxi, jobDifficulty[j]);
            dp[i][1] = maxi;
        }
        for(int day=2; day<=d; day++){
            for(int i=0; i<=n-day; i++){
                int maxi = INT_MIN, res = INT_MAX;
                for(int j=i; j<=n-day; j++){
                    maxi = max(maxi, jobDifficulty[j]);
                    res = min(res, maxi + dp[j+1][day-1]);
                }
                dp[i][day] = res;
            }
        }
        return dp[0][d];
    }

};

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<int>prev(n+1,0),curr(n+1,0);
        for(int i=0; i<n; i++){
            int maxi = INT_MIN;
            for(int j=i; j<n; j++) maxi = max(maxi, jobDifficulty[j]);
            prev[i] = maxi;
        }
        for(int day = 2; day <= d; day++){
            for(int i=0; i<=n-day; i++){
                int res = INT_MAX, maxi = INT_MIN;
                for(int j=i; j<=n-day; j++){
                    maxi = max(maxi, jobDifficulty[j]);
                    res = min(res, maxi + prev[j+1]);
                }
                curr[i] = res;
            }
            prev = curr;
        }
        return prev[0];
    }
};
