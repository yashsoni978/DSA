/*In a rotated sorted array:

One half is always sorted.
The minimum element lies in the unsorted half.
If the entire current range is already sorted, then the first element is the minimum.*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX, low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[low] <= nums[high]){//if whole array is sorted then minimum is the first ele
                ans = min(ans, nums[low]);
                break;
            }
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1; //ans maybe lie in right half
            }
            else{
                ans = min(ans, nums[mid]);
                high = mid - 1; //ans may lie in left half
            }
        }
        return ans;
    }
};