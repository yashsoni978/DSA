class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int zeroes = 0;
            for(int j=i; j<n; j++){
                if(nums[j] == 0) zeroes++;
                if(zeroes <= k) maxLen = max(maxLen, j-i+1);
                else break;
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, maxLen = 0, zeroes = 0;
        while(r < n){
            if(nums[r] == 0) zeroes++;
            while(zeroes > k){
                if(nums[l] == 0) zeroes--;
                l++;
            }
            if(zeroes <= k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};