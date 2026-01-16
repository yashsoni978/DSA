class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum >= target) minLen = min(minLen, j-i+1);
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, minLen = INT_MAX, sum = 0;
        while(r < n){
            sum += nums[r];
            while(sum >= target){
                minLen = min(minLen, r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};