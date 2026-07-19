<h2>416. Partition Equal Subset Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>nums</code>, return <code>true</code> if you can partition the array into <strong>two subsets</strong> such that the sum of the elements in both subsets is equal, and <code>false</code> otherwise.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,5,11,5]

<strong>Output:</strong>
true

<strong>Explanation:</strong>

The array can be partitioned as:

[1, 5, 5] and [11]

Both subsets have a sum of 11.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,2,3,5]

<strong>Output:</strong>
false

<strong>Explanation:</strong>

It is impossible to partition the array into
two subsets with equal sum.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ nums.length ≤ 200</code></li>
  <li><code>1 ≤ nums[i] ≤ 100</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> in <code>O(n × target)</code> time by reducing it to the <strong>Subset Sum</strong> problem, while optimizing the space complexity to <code>O(target)</code>?</p>
