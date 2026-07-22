class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1), hash(n);

        int maxi = 1, lastIndex = 0;

        for(int i = 0; i < n; i++) {
            hash[i] = i;

            for(int prev = 0; prev < i; prev++) {

                if(nums[i] % nums[prev] == 0 &&
                   dp[prev] + 1 > dp[i]) {

                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }

            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> ans;

        ans.push_back(nums[lastIndex]);

        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

/*TC: O(n²) — Sort the array and apply LIS-style DP using divisibility as the transition condition.
SC: O(n) — Uses dp, parent (hash), and result arrays for reconstruction.*/