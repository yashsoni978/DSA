class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int j=i; j<n; j++){
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                if(mini == minK && maxi == maxK) res++;
            }
        }
        return res;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long fixedSubarrays = 0;
        int minKPos = -1, maxKPos = -1, culpritIdx = -1;
        for(int i=0; i<n; i++){
            if(nums[i] < minK || nums[i] > maxK) culpritIdx = i;
            if(nums[i] == minK) minKPos = i;
            if(nums[i] == maxK) maxKPos = i;
            long long smaller = min(minKPos, maxKPos);
            long long temp = smaller - culpritIdx;
            fixedSubarrays += (temp < 0) ? 0 : temp;
        }
        return fixedSubarrays;
    }
};