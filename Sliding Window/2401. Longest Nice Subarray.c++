class Solution {
private:
    bool isNice(int start, int end, vector<int>& nums){
        int mask = 0;
        for(int i=start; i<=end; i++){
            if((mask & nums[i]) != 0) return false;
            mask |= nums[i];
        }
        return true;
    }
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isNice(i, j, nums)) res = max(res, j-i+1);
                else break;
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0; i<n; i++){
            int mask = 0;
            for(int j=i; j<n; j++){
                if((mask & nums[j]) != 0) break;
                res = max(res, j-i+1);
                mask |= nums[j];
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        int i = 0, j = 0, mask = 0;
        while(j < n){
            while((mask & nums[j]) != 0){
                mask ^= nums[i];
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            mask |= nums[j];
            j++;
        }
        return maxLen;
    }
};