class Solution {
  private:
    int solve(int day, int last, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(dp[day][last] != -1) return dp[day][last];
        if(day == 0){
            int maxi = 0;
            for(int i=0; i<=2; i++){
                if(i != last) maxi = max(maxi, mat[0][i]);
            }
            return dp[day][last] = maxi;
        }
        int maxi = 0;
        for(int i=0; i<=2; i++){
            if(i != last){
                int activity = mat[day][i] + solve(day-1, i, mat, dp);
                maxi = max(maxi, activity);
            }
        }
        return dp[day][last] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>>dp(n, vector<int>(4,-1));
        return solve(n-1, 3, mat, dp);
    }
};

/*TC: O(n × 4 × 3) ≈ O(n) — Each DP state (day, last activity) is computed once while checking all 3 activities.
SC: O(n) — O(n × 4) for the DP table and O(n) recursive call stack.*/

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>>dp(n, vector<int>(4,0));
        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][1]);
        dp[0][3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
        for(int day=1; day<n; day++){
            for(int last=0; last<=3; last++){
                dp[day][last] = 0;
                for(int task=0; task<=2; task++){
                    if(task != last){
                        int activity = mat[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
};

/*TC: O(n × 4 × 3) ≈ O(n) — Computes each (day, last activity) state once by checking all 3 tasks.
SC: O(n) — Uses a DP table of size n × 4.*/

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int>prev(4,0);
        prev[0] = max(mat[0][1], mat[0][2]);
        prev[1] = max(mat[0][0], mat[0][2]);
        prev[2] = max(mat[0][0], mat[0][1]);
        prev[3] = max(mat[0][0], max(mat[0][1], mat[0][2]));
        for(int day=1; day<n; day++){
            vector<int>curr(4,0);
            for(int last=0; last<=3; last++){
                curr[last] = 0;
                for(int task=0; task<=2; task++){
                    if(task != last){
                        int activity = mat[day][task] + prev[task];
                        curr[last] = max(curr[last], activity);
                    }
                }
            }
            prev = curr;
        }
        return prev[3];
    }
};

/*TC: O(n × 4 × 3) ≈ O(n) — Processes each day while checking all 3 tasks for every last activity state.
SC: O(1) — Uses only two arrays of size 4 for space-optimized dynamic programming.*/