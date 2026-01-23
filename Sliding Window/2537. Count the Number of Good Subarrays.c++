class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long cnt = 0;
        for(int i=0; i<n; i++){
            long long pairs = 0;
            unordered_map<int,int>mp;
            for(int j=i; j<n; j++){
                mp[nums[j]]++;
                if(mp[nums[j]] >= 2) pairs += mp[nums[j]] - 1;
                if(pairs >= k) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long cnt = 0, pairs = 0;
        unordered_map<int,int>mp;
        int i=0, j=0;
        while(j < n){
            pairs += mp[nums[j]];
            mp[nums[j]]++;
            while(pairs >= k){
                cnt += (n-j);
                mp[nums[i]]--;
                pairs -= mp[nums[i]];              
                i++;
            }
            j++;
        }
        return cnt;
    }
};

