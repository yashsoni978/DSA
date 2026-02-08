/*Q2. Merge Adjacent Equal Elements
Medium
4 pt.
You are given an integer array nums.

You must repeatedly apply the following merge operation until no more changes can be made:

If any two adjacent elements are equal, choose the leftmost such adjacent pair in the current array and replace them with a single element equal to their sum.
After each merge operation, the array size decreases by 1. Repeat the process on the updated array until no more changes can be made.

Return the final array after all possible merge operations.

 

Example 1:

Input: nums = [3,1,1,2]

Output: [3,4]

Explanation:

The middle two elements are equal and merged into 1 + 1 = 2, resulting in [3, 2, 2].
The last two elements are equal and merged into 2 + 2 = 4, resulting in [3, 4].
No adjacent equal elements remain. Thus, the answer is [3, 4].
Example 2:

Input: nums = [2,2,4]

Output: [8]

Explanation:

The first two elements are equal and merged into 2 + 2 = 4, resulting in [4, 4].
The first two elements are equal and merged into 4 + 4 = 8, resulting in [8].
Example 3:

Input: nums = [3,7,5]

Output: [3,7,5]

Explanation:

There are no adjacent equal elements in the array, so no operations are performed.

 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105​​​​​​​
*/

class Solution {
public:
    vector<int> mergeAdjacent(vector<int>& nums) {

        while (true) {

            bool merged = false;

            // Scan for leftmost equal pair
            for (int i = 0; i < nums.size() - 1; i++) {

                if (nums[i] == nums[i + 1]) {

                    // Merge them
                    nums[i] = nums[i] + nums[i + 1];

                    // Remove right element
                    nums.erase(nums.begin() + i + 1);

                    merged = true;

                    break;  // restart from beginning
                }
            }

            // If no merge happened → stop
            if (!merged) break;
        }

        return nums;
    }
};


class Solution {
public:
    vector<int> mergeAdjacent(vector<int>& nums) {

        vector<long long> st;  // use long long for safety

        for (long long num : nums) {

            st.push_back(num);

            // Merge while last two are equal
            while (st.size() >= 2) {

                int n = st.size();

                if (st[n - 1] == st[n - 2]) {

                    long long sum = st[n - 1] + st[n - 2];

                    st.pop_back();
                    st.pop_back();

                    st.push_back(sum);
                }
                else {
                    break;
                }
            }
        }

        // Convert back to int vector
        return vector<int>(st.begin(), st.end());
    }
};


