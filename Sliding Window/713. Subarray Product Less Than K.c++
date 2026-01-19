class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int prod = 1;
            for(int j=i; j<n; j++){
                prod *= nums[j];
                if(prod < k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0, prod = 1;
        if(k <= 1) return 0;
        while(r < n){
            prod *= nums[r];
            while(prod >= k){
                prod /= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};