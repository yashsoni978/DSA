class Solution {
private:
    bool canDivide(int divisor, vector<int>& nums, int threshold){
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += (nums[i] + divisor - 1) / divisor;//ceil(nums[i]/divisor)
        }
        if(sum <= threshold) return true;
        return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(canDivide(mid, nums, threshold)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};