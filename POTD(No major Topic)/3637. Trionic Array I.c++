class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n-1 && nums[i] < nums[i+1]) i++;
        if(i == 0) return false;
        int dec_i = i;
        while(i < n-1 && nums[i] > nums[i+1]) i++;
        if(i == dec_i) return false;
        int inc2_i = i;
        while(i < n-1 && nums[i] < nums[i+1]) i++;
        if(i == inc2_i) return false;
        return i == n-1;
    }
};