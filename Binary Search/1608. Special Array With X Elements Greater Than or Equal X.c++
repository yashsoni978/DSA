class Solution {
private:
    bool possible(int x, vector<int>& nums){
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] >= x) cnt++;
        }
        return cnt == x;
    }
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int special = -1;
        for(int num = 0; num <= n; num++){
            if(possible(num, nums)) special = num;
        }
        return special;
    }
};

class Solution {
private:
    int possible(int x, vector<int>& nums){
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(nums[i] >= x) cnt++;
        }
        return cnt;
    }
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(possible(mid, nums) == mid) return mid;
            else if(possible(mid, nums) > mid) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

};

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n+1);
        for(int i=0; i<n; i++) freq[min(n,nums[i])]++;
        int cumSum = 0;
        for(int x = n; x >= 0; x--){
            cumSum += freq[x];
            if(x == cumSum) return x;
        }
        return -1;
    }
};
