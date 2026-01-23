class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long cnt = 0;
        for(int i=0; i<n; i++){
            long long sum = 0;
            long long len = 0;
            long long score = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                len = (j-i+1);
                score = sum * len;
                if(score < k) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long cnt = 0, sum = 0;
        int i = 0, j = 0;
        while(j < n){
            sum += nums[j];
            while(i <= j && sum * (j-i+1) >= k){
                sum -= nums[i];
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
};