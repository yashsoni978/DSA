//tc - n*4*3
//sc - n + n*4
class Solution {
  private:
    int solve(int day, int last, vector<vector<int>>& dp, vector<vector<int>>& mat){
        if(day == 0){
            int maxi = 0;
            for(int task = 0; task <= 2; task++){
                if(task != last) maxi = max(maxi, mat[0][task]);
            }
            return maxi;
        }
        if(dp[day][last] != -1) return dp[day][last];
        int maxi = 0;
        for(int task = 0; task <= 2; task++){
            if(task != last){
                int activity = mat[day][task] + solve(day-1, task, dp, mat);
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
        return solve(n-1, 3, dp, mat);
    }
};

//Time → O(N × 4 × 3) ≈ O(N)
//Space → O(N × 4)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<vector<int>>dp(n, vector<int>(4,0));
        dp[0][0] = max(mat[0][1], mat[0][2]);
        dp[0][1] = max(mat[0][0], mat[0][2]);
        dp[0][2] = max(mat[0][0], mat[0][1]);
        dp[0][3] = max({mat[0][0], mat[0][1], mat[0][2]});
        for(int day = 1; day < n; day++){
            for(int last = 0; last <= 3; last++){
                dp[day][last] = 0;
                for(int task = 0; task <= 2; task++){
                    if(task != last) dp[day][last] = max(dp[day][last], mat[day][task] + dp[day-1][task]);
                }
            }
        }
        return dp[n-1][3];
    }
};

//time - n * 4 * 3
//space - o(1)
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int>prev(4,0);
        prev[0] = max(mat[0][1], mat[0][2]);
        prev[1] = max(mat[0][0], mat[0][2]);
        prev[2] = max(mat[0][0], mat[0][1]);
        prev[3] = max({mat[0][0], mat[0][1], mat[0][2]});
        for(int day=1; day<n; day++){
            vector<int>curr(4,0);
            for(int last=0; last<=3; last++){
                curr[last] = 0;
                for(int task=0; task<=2; task++){
                    if(task != last) curr[last] = max(curr[last], mat[day][task] + prev[task]);
                }
            }
            prev = curr;
        }
        return prev[3];
    }
};