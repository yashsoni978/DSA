class Solution {
private:
    bool canFormPairs(vector<int>& nums, int p, int mid){
        int cnt = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i+1] - nums[i] <= mid){
                cnt++;
                i++;
            }
        }
        return cnt >= p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0, high = nums[n-1] - nums[0];
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(canFormPairs(nums, p, mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};