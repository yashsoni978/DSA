class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum == k) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int pSum = 0;
        for(int i=0; i<n; i++){
            pSum += nums[i];
            int remove = pSum - k;
            if(mp.find(remove) != mp.end()) cnt += mp[remove];
            mp[pSum] += 1;
        }
        return cnt;
    }
};