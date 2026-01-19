class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int globalMax = *max_element(nums.begin(),nums.end());
        long long cnt = 0;
        for(int i=0; i<n; i++){
            int freq = 0;
            for(int j=i; j<n; j++){
                if(nums[j] == globalMax) freq++;
                if(freq >= k) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long cnt = 0;
        int l = 0, r = 0;
        int n = nums.size();
        int freq = 0, globalMax = *max_element(nums.begin(),nums.end());
        while(r < n){
            if(nums[r] == globalMax) freq++;
            while(freq >= k){
                cnt += (n-r);
                if(nums[l] == globalMax) freq--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};