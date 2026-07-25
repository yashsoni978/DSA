<h2>1043. Partition Array for Maximum Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>arr</code>, partition the array into contiguous subarrays of length <strong>at most</strong> <code>k</code>.</p>

<p>After partitioning, every element in a subarray becomes equal to the <strong>maximum element</strong> of that subarray.</p>

<p>Return the <strong>largest possible sum</strong> of the array after partitioning.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr = [1,15,7,9,2,5,10]
k = 3

<strong>Output:</strong>
84

<strong>Explanation:</strong>

One optimal partition is

[1,15,7] [9] [2,5,10]

After replacement, the array becomes

[15,15,15] [9] [10,10,10]

Sum = 45 + 9 + 30 = 84.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr = [1,4,1,5,7,3,6,1,9,9,3]
k = 4

<strong>Output:</strong>
83
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
arr = [1]
k = 1

<strong>Output:</strong>
1

<strong>Explanation:</strong>

Only one element exists,
so no partitioning changes
the array.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ arr.length ≤ 500</code></li>
  <li><code>0 ≤ arr[i] ≤ 10<sup>9</sup></code></li>
  <li><code>1 ≤ k ≤ arr.length</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> by letting <code>dp[i]</code> represent the maximum sum obtainable from index <code>i</code> onward, while trying every partition length from <code>1</code> to <code>k</code>, achieving <code>O(n × k)</code> time and <code>O(n)</code> space?</p>
