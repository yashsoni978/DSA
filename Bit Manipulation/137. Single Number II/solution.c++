class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int bitIndex = 0; bitIndex < 32; bitIndex++){
            int cnt = 0;
            for(int i=0; i<n; i++){
                if(nums[i] & (1 << bitIndex)) cnt++;
            }
            if(cnt % 3 == 1) ans |= (1 << bitIndex);
        }
        return ans;
    }
};
//n * 32

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=1; i<n; i+=3){
            if(nums[i] != nums[i-1]) return nums[i-1];
        }
        return nums[n-1];
    }
};
//n log n + n/3

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i=0; i<nums.size(); i++){
            ones = (ones ^ nums[i]) & (~twos);
            twos = (twos ^ nums[i]) & (~ones);
        }
        return ones;
    }
};
//n