class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for (int x : nums) {
            sum += x;

            if (mp.find(sum - goal) != mp.end()) {
                count += mp[sum - goal];
            }

            mp[sum]++;
        }

        return count;
    }
};

//n and n

class Solution {
private:
    int helper(vector<int>& nums, int goal){
        int n = nums.size();
        int l = 0, r = 0, cnt = 0, sum = 0;
        if(goal < 0) return 0;
        while(r < n){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal - 1);
    }
};