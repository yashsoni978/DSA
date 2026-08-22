class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        int ans = INT_MAX, low = 0, high = nums.size() - 1, index = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[low] <= nums[high]){//if whole array is sorted then minimum is the first ele
                if(nums[low] < ans){
                    ans = nums[low];
                    index = low;
                }
                break;
            }
            if(nums[low] <= nums[mid]){
                if(nums[low] < ans){
                    ans = nums[low];
                    index = low;
                }
                low = mid + 1;
            }
            else{
                if(nums[mid] < ans){
                    ans = nums[mid];
                    index = mid;
                }
                high = mid - 1;
            }
        }
        return index;
    }
};
