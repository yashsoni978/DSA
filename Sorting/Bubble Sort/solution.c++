class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;

            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped) break;
        }

        return nums;
    }
};

// TC: O(N^2) worst case, O(N) best case
// SC: O(1)

//Striver style
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = n - 1; i >= 1; i--) {
            for (int j = 0; j <= i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }

        return nums;
    }
};

// TC: O(N^2)
// SC: O(1)
