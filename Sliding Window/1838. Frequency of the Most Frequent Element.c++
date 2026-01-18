class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int cost = 0, cnt = 1;
            for(int j=i-1; j>=0; j--){
                cost += nums[i] - nums[j];
                if(cost > k) break;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

class Solution {
private:
    int find(int targetIdx, int k, vector<int>& nums, vector<long>& pSum){
        int n = nums.size();
        int i = 0, j = targetIdx;
        int target = nums[targetIdx];
        int res = targetIdx;
        while(i <= j){
            int mid = i + (j-i) / 2;
            long cnt = (targetIdx - mid + 1);
            long windowSum = cnt * nums[targetIdx];
            long currSum = pSum[targetIdx] - pSum[mid] + nums[mid];
            int ops = windowSum - currSum;
            if(ops > k) i = mid + 1;
            else{
                res = mid;
                j = mid - 1;
            }
        }
        return targetIdx - res + 1;
    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long>pSum(n,0);
        pSum[0] = nums[0];
        for(int i=1; i<n; i++) pSum[i] = pSum[i-1] + nums[i];
        int res = 0;
        for(int i=0; i<n; i++) res = max(res, find(i, k, nums, pSum));
        return res;
    }
};

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        long currSum = 0;
        int j = 0, res = 0;
        while(j < n){
            long target = nums[j];
            currSum += nums[j];
            if((j-i+1) * target - currSum > k){
                currSum -= nums[i];
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res; 
    }
};