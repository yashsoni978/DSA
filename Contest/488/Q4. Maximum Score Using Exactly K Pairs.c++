/*Q4. Maximum Score Using Exactly K Pairs
Solved
Hard
6 pt.
You are given two integer arrays nums1 and nums2 of lengths n and m respectively, and an integer k.

You must choose exactly k pairs of indices (i1, j1), (i2, j2), ..., (ik, jk) such that:

0 <= i1 < i2 < ... < ik < n
0 <= j1 < j2 < ... < jk < m
For each chosen pair (i, j), you gain a score of nums1[i] * nums2[j].

The total score is the sum of the products of all selected pairs.

Return an integer representing the maximum achievable total score.

 

Example 1:

Input: nums1 = [1,3,2], nums2 = [4,5,1], k = 2

Output: 22

Explanation:

One optimal choice of index pairs is:

(i1, j1) = (1, 0) which scores 3 * 4 = 12
(i2, j2) = (2, 1) which scores 2 * 5 = 10
This gives a total score of 12 + 10 = 22.

Example 2:

Input: nums1 = [-2,0,5], nums2 = [-3,4,-1,2], k = 2

Output: 26

Explanation:

One optimal choice of index pairs is:

(i1, j1) = (0, 0) which scores -2 * -3 = 6
(i2, j2) = (2, 1) which scores 5 * 4 = 20
The total score is 6 + 20 = 26.

Example 3:

Input: nums1 = [-3,-2], nums2 = [1,2], k = 2

Output: -7

Explanation:

The optimal choice of index pairs is:

(i1, j1) = (0, 0) which scores -3 * 1 = -3
(i2, j2) = (1, 1) which scores -2 * 2 = -4
The total score is -3 + (-4) = -7.

 

Constraints:

1 <= n == nums1.length <= 100
1 <= m == nums2.length <= 100
-106 <= nums1[i], nums2[i] <= 106
1 <= k <= min(n, m)*/

class Solution {
public:
    long long maxScore(vector<int>& nums1,
                       vector<int>& nums2,
                       int k) {

        int n = nums1.size();
        int m = nums2.size();

        const long long NEG = -1e18;

        // dp[i][j][p]
        vector dp(n+1,
            vector(m+1,
                vector<long long>(k+1, NEG)));

        // base: 0 pairs = 0 score
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                dp[i][j][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int p = 1; p <= k; p++) {

                    long long pairScore =
                        (long long)nums1[i-1] *
                        nums2[j-1];

                    dp[i][j][p] = max({
                        dp[i-1][j][p],          // skip nums1
                        dp[i][j-1][p],          // skip nums2
                        dp[i-1][j-1][p-1] + pairScore // pair
                    });
                }
            }
        }

        return dp[n][m][k];
    }
};
