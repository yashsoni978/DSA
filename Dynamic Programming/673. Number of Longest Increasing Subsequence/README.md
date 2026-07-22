<h2>673. Number of Longest Increasing Subsequence</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>nums</code>, return the <strong>number of longest increasing subsequences</strong>.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.</p>

<p>An <strong>increasing subsequence</strong> is a subsequence in which every element is <strong>strictly greater</strong> than its previous element.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,3,5,4,7]

<strong>Output:</strong>
2

<strong>Explanation:</strong>

The two longest increasing
subsequences are

[1,3,4,7]
and
[1,3,5,7]

Both have length 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [2,2,2,2,2]

<strong>Output:</strong>
5

<strong>Explanation:</strong>

Each individual element forms
an increasing subsequence of
length 1.

Hence there are 5 longest
increasing subsequences.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ nums.length ≤ 2000</code></li>
  <li><code>-10<sup>6</sup> ≤ nums[i] ≤ 10<sup>6</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> by maintaining two arrays—one for the length of the LIS ending at each index and another for the number of such LIS—achieving <code>O(n²)</code> time and <code>O(n)</code> space?</p>
