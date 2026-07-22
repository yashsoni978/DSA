class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1), cnt(n,1);
        int maxi = 1;
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[prev] < nums[i] && dp[prev] + 1 > dp[i]){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(nums[prev] < nums[i] && dp[prev] + 1 == dp[i]) cnt[i] += cnt[prev];
            }
            maxi = max(maxi, dp[i]);
        }
        int noOfLIS = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxi) noOfLIS += cnt[i]; 
        }
        return noOfLIS;
    }
};

/*TC: O(n²) — For each element, check all previous elements to compute the LIS length and count of LIS ending at that index.
SC: O(n) — Uses two arrays: dp[i] for LIS length and cnt[i] for the number of LIS ending at index i.*/