class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int minValue = INT_MAX;
        for(int i=0; i<n; i++){
            int currOR = 0;
            for(int j=i; j<n; j++){
                currOR |= nums[j];
                minValue = min(minValue, abs(currOR - k));
            }
        }
        return minValue;
    }
};

//Optimal - Will not get accepted on LC - WA
class Solution {
private:
    void updateFreq(int op, int val, vector<int>& freqBits){
        int i = 0;
        while(val > 0){
            if(val & 1) freqBits[i] += op;
            val >>= 1;
            i++;
        }
    }
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>freqBits(32,0);
        int i = 0, windowOR = 0, res = INT_MAX;
        for(int j=0; j<n; j++){
            updateFreq(1, nums[j], freqBits);
            windowOR |= nums[j];
            res = min(res, abs(windowOR - k));
            while(i <= j && windowOR > k){
                updateFreq(-1, nums[i], freqBits);
                i++;
                windowOR = 0;
                for(int b=0; b<32; b++){
                    if(freqBits[b] > 0) windowOR |= (1 << b);
                }
                res = min(res, abs(windowOR - k));
            }
            if(windowOR == k) return 0;
        }
        return res;
    }
};