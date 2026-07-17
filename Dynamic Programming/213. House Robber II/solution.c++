class Solution {
private:
    long long solve(vector<int>& nums) {
        int n = nums.size();
        long long prev = nums[0], prev2 = 0;
        for(int i=1; i<n; i++){
            long long pick = nums[i];
            if(i > 1) pick += prev2;
            long long notPick = prev;
            long long curr = INT_MIN;
            curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>arr1,arr2;
        for(int i=0; i<n; i++){
            if(i != 0) arr1.push_back(nums[i]);
            if(i != n-1) arr2.push_back(nums[i]);
        }
        long long ans1 = solve(arr1);
        long long ans2 = solve(arr2);
        return max(ans1, ans2);
    }
};

/*TC: O(n) — Creates two arrays and computes the maximum robbery amount for each in linear time.
SC: O(n) — Uses two auxiliary arrays of size n−1; the helper function uses constant extra space.*/