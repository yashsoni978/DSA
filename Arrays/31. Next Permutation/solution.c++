class Solution {
public:
    void generatePermutations(vector<int>& nums, int index,
                              vector<vector<int>>& allPermutations) {
        if (index == nums.size()) {
            allPermutations.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);

            generatePermutations(nums, index + 1, allPermutations);

            swap(nums[index], nums[i]);
        }
    }
 
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> allPermutations;

        // Generate all permutations
        generatePermutations(nums, 0, allPermutations);

        // Sort all permutations
        sort(allPermutations.begin(), allPermutations.end());

        // Find current permutation
        for (int i = 0; i < allPermutations.size(); i++) {
            if (allPermutations[i] == nums) {

                // If current is the last permutation
                if (i == allPermutations.size() - 1) {
                    nums = allPermutations[0];
                }
                else {
                    nums = allPermutations[i + 1];
                }

                return;
            }
        }
    }
};
// TC: O(N! * N)
// SC: O(N! * N)
// N = size of array

//Better
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
        return nums;
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){//this is the last part so reverse it and give it as first part
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=n-1; i>=ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
// TC: O(N)
// SC: O(1)
// N = size of nums
