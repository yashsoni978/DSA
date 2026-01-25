class Solution {
private:
    int solve(int idx, int prev, string &s, vector<vector<int>>& dp){
        int n = s.length();
        if(idx == n) return 0;
        if(dp[idx][prev] != -1) return dp[idx][prev];
        int flip = 1e9, notFlip = 1e9;
        if(s[idx] == '0'){
            if(prev == 1){
                flip = 1 + solve(idx+1, 1, s, dp);
            }
            else{
                notFlip = solve(idx+1, 0, s, dp);
                flip = 1 + solve(idx+1, 1, s, dp);
            }
        }
        else{
            if(prev == 1){
                notFlip = solve(idx+1, 1, s, dp);
            }
            else{
                notFlip = solve(idx+1, 1, s, dp);
                flip = 1 + solve(idx+1, 0, s, dp);
            }
        }
        return dp[idx][prev] = min(flip, notFlip);
    }
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return solve(0, 0, s, dp);
    }
};

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        for(int i=1; i<=n; i++){
            if(s[i-1] == '0'){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + 1;
            }
            else{
                dp[i][0] = dp[i-1][0] + 1;
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            }
        }
        return min(dp[n][0], dp[n][1]);
    }
};

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cntOfOnes = 0;
        int flips = 0;
        for(char &ch : s){
            if(ch == '1') cntOfOnes++;
            else{
                flips = min(flips+1, cntOfOnes);
            }
        }
        return flips;
    }
};