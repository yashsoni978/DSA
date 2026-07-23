class Solution {
private:
    long long solve(int i, int j, vector<int>& cuts, vector<vector<long long>>& dp){
        if(i > j) return 0;//no more sticks to cut
        if(dp[i][j] != -1) return dp[i][j];
        long long mini = 1e9;
        for(int k=i; k<=j; k++){
            long long cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp) + solve(k+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());//to make recursion right
        int c = cuts.size();
        vector<vector<long long>>dp(c, vector<long long>(c,-1));
        return solve(1, c-2, cuts, dp);//c-2 because the last index should be c-2
    }
};

/*TC: O(c³) — There are O(c²) subproblems, and each tries all possible first cuts in O(c) time.
SC: O(c²) + O(c) — O(c²) DP table for memoization and O(c) recursion stack depth.*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        vector<vector<int>>dp(c, vector<int>(c,0));
        for(int i=c-2; i>=1; i--){
            for(int j=1; j<=c-2; j++){
                if(i > j) continue;
                int mini = INT_MAX;
                for(int k=i; k<=j; k++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c-2];
    }
};

/*TC: O(c³) — Fill O(c²) DP states, and each state tries all possible first cuts in O(c).
SC: O(c²) — Uses only a 2D DP table; recursion stack is eliminated in tabulation.*/