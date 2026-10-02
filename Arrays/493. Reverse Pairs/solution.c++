class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((long long)nums[i] > (long long)2 * nums[j]) cnt++;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while(left <= mid)
            temp.push_back(nums[left++]);

        while(right <= high)
            temp.push_back(nums[right++]);

        for(int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }

        return 0;
    }

    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;

        for(int i = low; i <= mid; i++) {

            while(right <= high &&
                  (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }

            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high)
            return 0;

        int mid = (low + high) / 2;

        int cnt = 0;

        cnt += mergeSort(nums, low, mid);

        cnt += mergeSort(nums, mid + 1, high);

        cnt += countPairs(nums, low, mid, high);

        merge(nums, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

//2nlogn
//sc :- distorting the array