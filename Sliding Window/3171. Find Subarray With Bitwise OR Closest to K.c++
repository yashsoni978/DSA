class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int minValue = INT_MAX;
        for(int i=0; i<n; i++){
            int currOR = 0;
            for(int j=i; j<n; j++){
                currOR |= nums[j];
                minValue = min(minValue, abs(currOR - k));
            }
        }
        return minValue;
    }
};

//Optimal - Skip no perfect tutorial