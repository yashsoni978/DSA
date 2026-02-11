class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        long long ans = LLONG_MAX;
        for(int target=mini; target<=maxi; target++){
            long long totalCost = 0;
            for(int i=0; i<n; i++) totalCost += 1LL * abs(nums[i] - target) * cost[i];
            ans = min(ans, totalCost);
        }
        return ans;
    }
};

class Solution {
private:
    long long getCost(vector<int>& nums, vector<int>& cost, long long target){
        long long total = 0;
        for(int i=0; i<nums.size(); i++) total += 1LL * abs(nums[i] - target) * cost[i];
        return total; 
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long l = *min_element(nums.begin(), nums.end());
        long long r = *max_element(nums.begin(), nums.end());
        while(l < r){
            long long mid = l + (r-l) / 2;
            long long cost1 = getCost(nums, cost, mid);
            long long cost2 = getCost(nums, cost, mid+1);
            if(cost1 > cost2) l = mid + 1;
            else r = mid;
        }
        return getCost(nums, cost, l);
    }
};