class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2*k+1;
        vector<int>ans(n,-1);
        for(int i=0; i<n; i++){
            if(i - k < 0 || i + k >= n) continue;
            long long sum = 0;
            for(int j=i-k; j<=i+k; j++){
                sum += nums[j];
            }
            ans[i] = sum / windowSize;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res(n,-1);
        if(k == 0) return nums;
        if(n < 2*k+1) return res;
        int left = 0, right = 2*k, i = k, cnt = 2*k+1;
        long long window = 0;
        for(int i=left; i<=right; i++) window += nums[i];
        res[i] = window / cnt;
        i++;
        right++;
        while(right < n){
            int oldValue = nums[left], newValue = nums[right];
            window += newValue - oldValue;
            res[i] = window / cnt;
            i++;
            left++;
            right++;
        }
        return res;
    }
};