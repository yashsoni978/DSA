class Solution {
private:
    int bS(vector<vector<int>>& jobs, int idx, int n){
        int low = idx+1, high = n-1, ans = n;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(jobs[mid][0] >= jobs[idx][1]){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
    int solve(int idx, vector<vector<int>>& jobs, vector<int>& dp, int n){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int nextIdx = bS(jobs, idx, n);
        int take = jobs[idx][2] + solve(nextIdx, jobs, dp, n);
        int notTake = solve(idx + 1, jobs, dp, n);
        return dp[idx] = max(take, notTake);
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs(n, vector<int>(3));
        for(int i=0; i<n; i++) jobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());
        vector<int>dp(n,-1);
        return solve(0, jobs, dp, n);
    }
};

class Solution {
private:
    int getNextIdx(vector<vector<int>>& jobs, int idx){
        int low = 0;
        int high = idx - 1;
        int ans = -1;
        
        while(low <= high) {
            
            int mid = low + (high - low) / 2;
            
            if(jobs[mid][1] <= jobs[idx][0]) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs(n, vector<int>(3));
        for(int i=0; i<n; i++) jobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(jobs.begin(), jobs.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        vector<int>dp(n,0);
        dp[0] = jobs[0][2];
        for(int i=1; i<n; i++){
            int take = jobs[i][2];
            int last = getNextIdx(jobs, i);
            if(last != -1) take += dp[last];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[n-1];
    }
};