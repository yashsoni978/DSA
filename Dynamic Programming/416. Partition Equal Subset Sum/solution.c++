class Solution {
private: 
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<bool>prev(sum+1, false);
        prev[0] = true;
        if(arr[0] <= sum) prev[arr[0]] = true;
        for(int ind = 1; ind < n; ind++){
            vector<bool>curr(sum+1, false);
            curr[0] = true;
            for(int target = 1; target <= sum; target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target) take = prev[target - arr[ind]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(int num : nums) totSum += num;
        if(totSum % 2) return false;
        int target = totSum / 2;
        return isSubsetSum(nums, target);
    }
};

/*TC: O(n × target) — Computes each (index, target) state once using space-optimized dynamic programming, where target = totalSum / 2.
SC: O(target) — Uses two 1D arrays of size (target + 1) instead of a 2D DP table.*/