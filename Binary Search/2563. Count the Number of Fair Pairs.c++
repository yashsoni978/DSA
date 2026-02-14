class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<pair<int,int>>ans;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){// it needs pairs i < j
                if((nums[i] + nums[j]) >= lower && (nums[i] + nums[j]) <= upper) ans.push_back({i, j});
            }
        }
        return ans.size();
    }
};

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long cnt = 0;
        for(int i=0; i<n; i++){
            int idx = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int x = idx - 1 - i;
            idx = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            int y = idx - 1 - i;
            cnt += (y-x);
        }
        return cnt;
    }
};