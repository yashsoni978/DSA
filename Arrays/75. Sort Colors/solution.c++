class Solution {
public:

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }

    void sortColors(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
    }
};
// TC: O(N log N)
// SC: O(N)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0) cnt0++;
            else if(nums[i] == 1) cnt1++;
            else cnt2++;
        }
        for(int i=0; i<cnt0; i++) nums[i] = 0;
        for(int i=cnt0; i<cnt0+cnt1; i++) nums[i] = 1;
        for(int i=cnt0+cnt1; i<n; i++) nums[i] = 2;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) mid++;
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
