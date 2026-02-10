class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr = nums;
        int bestMax = *max_element(arr.begin(), arr.end());
        bool changed = true;
        while(changed){
            changed = false;
            for(int i=n-1; i>0; i--){
                if(arr[i] > arr[i-1]){
                    arr[i]--;
                    arr[i-1]++;
                    changed = true;
                }
            }
            int currentMax = *max_element(arr.begin(),arr.end());
            bestMax = min(bestMax, currentMax);
        }
        return bestMax;
    }
};

class Solution {
private:
    bool isValid(vector<int>& nums, int maxMid, int n){
        vector<long long>arr(nums.begin(),nums.end());
        for(int i=0; i<n-1; i++){
            if(arr[i] > maxMid) return false;
            long long buffer = maxMid - arr[i];
            arr[i+1] = arr[i+1] - buffer;
        }
        return arr[n-1] <= maxMid;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int maxL = 0;
        int maxR = *max_element(nums.begin(),nums.end());
        int res;
        while(maxL <= maxR){
            int maxMid = maxL + (maxR - maxL)/2;
            if(isValid(nums, maxMid, n)){
                res = maxMid;
                maxR = maxMid - 1;
            }
            else maxL = maxMid + 1;
        }
        return res;
    }
};class Solution {
private:
    bool isValid(vector<int>& nums, int maxMid, int n){
        vector<long long>arr(nums.begin(),nums.end());
        for(int i=0; i<n-1; i++){
            if(arr[i] > maxMid) return false;
            long long buffer = maxMid - arr[i];
            arr[i+1] = arr[i+1] - buffer;
        }
        return arr[n-1] <= maxMid;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int maxL = 0;
        int maxR = *max_element(nums.begin(),nums.end());
        int res;
        while(maxL <= maxR){
            int maxMid = maxL + (maxR - maxL)/2;
            if(isValid(nums, maxMid, n)){
                res = maxMid;
                maxR = maxMid - 1;
            }
            else maxL = maxMid + 1;
        }
        return res;
    }
};