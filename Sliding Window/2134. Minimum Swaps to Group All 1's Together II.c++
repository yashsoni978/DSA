class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int x : nums){
            if(x == 1) ones++;
        }
        if(ones == 0 || ones == n) return 0;
        vector<int>arr;
        for(int i=0; i<2*n; i++) arr.push_back(nums[i%n]);
        int ans = INT_MAX;
        for(int i=0; i<2*n-ones; i++){
            int zeroCnt = 0;
            for(int j=i; j<i+ones; j++){
                if(arr[j] == 0) zeroCnt++;
            }
            ans = min(ans, zeroCnt);
        }
        return ans;
    }
};

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        for(int i=0; i < 2*n; i++) arr.push_back(nums[i%n]);
        int cntOnes = accumulate(nums.begin(), nums.end(), 0);
        int i = 0, j = 0, currCnt = 0, maxCnt = 0;
        while(j < 2*n){
            if(arr[j] == 1) currCnt++;
            if(j-i+1 > cntOnes){
                currCnt -= arr[i];
                i++;
            }
            maxCnt = max(maxCnt, currCnt);
            j++;
        }
        return cntOnes - maxCnt;
    }
};

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cntOnes = accumulate(nums.begin(),nums.end(),0);
        int i = 0, j = 0, currCnt = 0, maxCnt = 0;
        while(j < 2*n){
            if(nums[j%n] == 1) currCnt++;
            if(j-i+1 > cntOnes){
                currCnt -= nums[i%n];
                i++;
            }
            maxCnt = max(maxCnt, currCnt);
            j++;
        }
        return cntOnes - maxCnt;
    }
};