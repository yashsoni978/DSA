class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            int flag = 0;
            for(int j=0; j<n; j++){
                if(nums[j] == i){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) return i;
        }
        return n;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>hash(n+1,0);
        for(int i=0; i<n; i++) hash[nums[i]] = 1;
        for(int i=0; i<n; i++){
            if(hash[i] == 0) return i;
        }
        return n;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2, S2 = 0;
        for(int i=0; i<n; i++) S2 += nums[i];
        return (sum - S2);
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;
        for(int i=0; i<=n; i++) xor1 ^= i;
        for(int i=0; i<n; i++) xor2 ^= nums[i];
        return (xor1 ^ xor2);
    }
};