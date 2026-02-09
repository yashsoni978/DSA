//f(4,N) => Till index 4 what is the maximum price to obtain
// rod length N 
// User function Template for C++

class Solution {
  private:
    int solve(int ind, int n, vector<int>& price, vector<vector<int>>& dp){
        if(ind == 0) return price[0] * n;
        if(dp[ind][n] != -1) return dp[ind][n];
        int notTake = solve(ind-1, n, price, dp);
        int take = INT_MIN;
        int rodLength = ind + 1;
        if(rodLength <= n) take = price[ind] + solve(ind, n - rodLength, price, dp);
        return dp[ind][n] = max(take, notTake);
    }
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));
        return solve(n-1, n, price, dp);
    }
};

// User function Template for C++

// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>>dp(n, vector<int>(n+1,0));
        for(int i=0; i<=n; i++) dp[0][i] = price[0] * i;
        for(int ind=1; ind<n; ind++){
            for(int N=0; N<=n; N++){//starting from 1 will also work
                int notTake = dp[ind-1][N];
                int take = INT_MIN;
                int rodLength = ind+1;
                if(rodLength <= N) take = price[ind] + dp[ind][N - rodLength];
                dp[ind][N] = max(take, notTake);
            }
        }
        return dp[n-1][n];
    }
};

// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int>prev(n+1,0);
        for(int i=0; i<=n; i++) prev[i] = price[0] * i;
        for(int ind=1; ind<n; ind++){
            vector<int>curr(n+1,0);
            for(int N=0; N<=n; N++){//starting from 1 will also work
                int notTake = prev[N];
                int take = INT_MIN;
                int rodLength = ind+1;
                if(rodLength <= N) take = price[ind] + curr[N - rodLength];
                curr[N] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[n];
    }
};


