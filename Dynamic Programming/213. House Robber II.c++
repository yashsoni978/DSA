class Solution {
private:
    int solve(vector<int>& nums){
        int n = nums.size();
        int prev = 0, prev2 = 0;
        for(int i=1; i<=n; i++){
            int skip = prev;
            int take = nums[i-1];
            if(i > 1) take += prev2;
            int curr_i = max(skip, take);
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>temp1,temp2;
        for(int i=0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1),solve(temp2));
    }
};