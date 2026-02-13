class Solution {
private:
    long long costToMakeEqual(vector<int>& nums, int l, int r, int target){
        long long cost = 0;
        for(int i=l; i<=r; i++){
            cost += abs(nums[i] - target);
        }
        return cost;
    }
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 1;
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int t=i; t<=j; t++){
                    long long cost = costToMakeEqual(nums, i, j, nums[t]);
                    if(cost <= k) ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};

class Solution {
private:
    bool possible(int len, vector<long long>& pSum, vector<int>& nums, long long k){
        int i = 0, j = len - 1;
        int n = nums.size();
        while(j < n){
            long long targetIdx = (i+j) / 2;
            long long target = nums[targetIdx];
            long long operationsLeft = 0;
            if(targetIdx - i == 0) operationsLeft = 0;
            else operationsLeft = abs((targetIdx - i) * target) - (pSum[targetIdx - 1] - (i > 0 ? pSum[i-1] : 0));
            long long operationsRight = abs(((j - targetIdx) * target) - (pSum[j] - pSum[targetIdx]));
            if(operationsLeft + operationsRight <= k) return true;
            i++;
            j++;
        }
        return false;
    }
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++) prefix[i] = prefix[i-1] + nums[i];
        int minScore = 1, maxScore = n, res = 0;
        while(minScore <= maxScore){
            int midScore = minScore + (maxScore - minScore) / 2;
            if(possible(midScore, prefix, nums, k)){
                res = midScore;
                minScore = midScore + 1;
            }
            else maxScore = midScore - 1;
        }
        return res;
    }
};