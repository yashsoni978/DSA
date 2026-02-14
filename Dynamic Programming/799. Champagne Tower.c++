class Solution {
private:
    double solve(int poured, int i, int j, vector<vector<double>>& dp){
        if(i < 0 || j < 0 || i < j) return 0.0;
        if(i == 0 && j == 0) return poured;
        if(dp[i][j] != -1) return dp[i][j];
        double upLeft = (solve(poured, i-1, j-1, dp) - 1) / 2;
        double upRight = (solve(poured, i-1, j, dp) - 1) /2;
        if(upLeft < 0) upLeft = 0.0;
        if(upRight < 0) upRight = 0.0;
        return dp[i][j] = upLeft + upRight;
    }
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(101, vector<double>(101,-1));
        return min(1.0, solve(poured, query_row, query_glass, dp));
    }
};

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>dp(101, vector<double>(101,0.0));
        dp[0][0] = poured;
        for(int i=0; i<100; i++){
            for(int j=0; j<=i; j++){
                if(dp[i][j] > 1.0){
                    double overflow = (dp[i][j] - 1.0) / 2.0;
                    dp[i+1][j] += overflow;
                    dp[i+1][j+1] += overflow;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>prev(101,0.0);
        prev[0] = poured;
        for(int i=0; i<query_row; i++){ //if 100 then prev stores upto row 100, not the row I want
            vector<double>ahead(101,0.0);
            for(int j=0; j<=i; j++){
                if(prev[j] > 1.0){
                    double overflow = (prev[j] - 1.0) / 2.0;
                    ahead[j] += overflow;
                    ahead[j+1] += overflow;
                }
            }
            prev = ahead;
        }
        return min(1.0, prev[query_glass]);
    }
};