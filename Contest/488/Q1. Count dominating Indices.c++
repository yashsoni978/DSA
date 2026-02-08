/*Q1. Count Dominant Indices
Easy
3 pt.
You are given an integer array nums of length n.

An element at index i is called dominant if: nums[i] > average(nums[i + 1], nums[i + 2], ..., nums[n - 1])

Your task is to count the number of indices i that are dominant.

The average of a set of numbers is the value obtained by adding all the numbers together and dividing the sum by the total number of numbers.

Note: The rightmost element of any array is not dominant.

 

Example 1:

Input: nums = [5,4,3]

Output: 2

Explanation:

At index i = 0, the value 5 is dominant as 5 > average(4, 3) = 3.5.
At index i = 1, the value 4 is dominant over the subarray [3].
Index i = 2 is not dominant as there are no elements to its right. Thus, the answer is 2.
Example 2:

Input: nums = [4,1,2]

Output: 1

Explanation:

At index i = 0, the value 4 is dominant over the subarray [1, 2].
At index i = 1, the value 1 is not dominant.
Index i = 2 is not dominant as there are no elements to its right. Thus, the answer is 1.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100​​​​​​​
*/

class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int n = nums.size();
        int dominant = 0;

        // Traverse till second last index
        for (int i = 0; i < n - 1; i++) {

            int rightSum = 0;
            int rightCount = 0;

            // Calculate right side sum
            for (int j = i + 1; j < n; j++) {
                rightSum += nums[j];
                rightCount++;
            }

            double avg = (double)rightSum / rightCount;

            if (nums[i] > avg) {
                dominant++;
            }
        }

        return dominant;
    }
};


class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) return 0;

        long long totalSum = 0;

        // Step 1: Find total sum
        for (int num : nums) {
            totalSum += num;
        }

        long long rightSum = totalSum;
        int dominant = 0;

        // Step 2: Traverse till second last index
        for (int i = 0; i < n - 1; i++) {

            rightSum -= nums[i];          // remove current element
            int rightCount = n - i - 1;  // elements on right

            if ((long long)nums[i] * rightCount > rightSum) {
                dominant++;
            }
        }

        return dominant;
    }
};
