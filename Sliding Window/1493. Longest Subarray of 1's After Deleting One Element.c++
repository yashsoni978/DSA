class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int zeroes = 0;
            for(int j=i; j<n; j++){
                if(nums[j] == 0) zeroes++;
                if(zeroes <= 1) maxLen = max(maxLen, j-i+1);
            }
        }
        return maxLen-1;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, maxLen = INT_MIN, zeroes = 0, k = 1;
        while(r < n){
            if(nums[r] == 0) zeroes++;
            if(zeroes > k){
                if(nums[l] == 0) zeroes--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++; 
        }
        return maxLen == INT_MIN ? 0 : maxLen - 1;
    }
};