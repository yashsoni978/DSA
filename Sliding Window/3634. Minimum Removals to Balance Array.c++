class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0, r = 0, maxLen = 0;
        while(r < n){
            while((long long)nums[r] > (long long)nums[l] * k) l++;
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return n - maxLen;
    }
};

