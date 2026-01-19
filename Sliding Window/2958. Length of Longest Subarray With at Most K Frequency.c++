class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            unordered_map<int,int>mp;
            for(int j=i; j<n; j++){
                mp[nums[j]]++;
                if(mp[nums[j]] <= k) maxLen = max(maxLen, j-i+1);
                else break;
            }
        }
        return maxLen;
    }
};

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0, maxLen = 0;
        unordered_map<int,int>mp;
        while(r < n){
            mp[nums[r]]++;
            while(mp[nums[r]] > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            } 
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};