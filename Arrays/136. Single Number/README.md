<h2>136. Single Number</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Problem Statement</h3>

<p>
Given a non-empty array of integers <code>nums</code>, every element appears twice except for one element which appears exactly once.
Return the element that appears only once.
</p>

<h3>Example</h3>

<pre>
Input:  nums = [4,1,2,1,2]

Output: 4
</pre>

<h3>Approach</h3>

<p>
We use the <b>XOR</b> operation.
</p>

<ul>
<li><code>a ^ a = 0</code></li>
<li><code>a ^ 0 = a</code></li>
<li>XOR is commutative and associative.</li>
</ul>

<p>
Therefore, all duplicate elements cancel each other out, leaving only the element that appears once.
</p>

<pre>
4 ^ 1 ^ 2 ^ 1 ^ 2

= 4 ^ (1 ^ 1) ^ (2 ^ 2)

= 4 ^ 0 ^ 0

= 4
</pre>

<h3>Code</h3>

<pre>
class Solution {
public:
    int singleNumber(vector&lt;int&gt;&amp; nums) {
        int ans = 0;

        for (int num : nums) {
            ans = ans ^ num;
        }

        return ans;
    }
};
</pre>

<h3>Complexity</h3>

<pre>
// TC: O(N)
// SC: O(1)
// N = number of elements in nums
</pre>

<h3>Key Point</h3>

<p>
Whenever every number appears twice except one, <b>XOR</b> is the optimal approach because duplicate numbers cancel themselves out.
</p>
