<h2>368. Largest Divisible Subset</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a set of <strong>distinct positive integers</strong> <code>nums</code>, return the <strong>largest subset</strong> such that every pair <code>(answer[i], answer[j])</code> of elements in the subset satisfies:</p>

<ul>
  <li><code>answer[i] % answer[j] == 0</code>, or</li>
  <li><code>answer[j] % answer[i] == 0</code>.</li>
</ul>

<p>If there are multiple valid solutions, return <strong>any</strong> of them.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,2,3]

<strong>Output:</strong>
[1,2]

<strong>Explanation:</strong>

Both

[1,2]

and

[1,3]

are valid largest divisible subsets.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,2,4,8]

<strong>Output:</strong>
[1,2,4,8]

<strong>Explanation:</strong>

Every element divides the next one.

Hence the entire array forms
the largest divisible subset.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ nums.length ≤ 1000</code></li>
  <li><code>1 ≤ nums[i] ≤ 2 × 10<sup>9</sup></code></li>
  <li>All integers in <code>nums</code> are <strong>unique</strong>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> by first sorting the array, maintaining the length of the largest divisible subset ending at each index, and reconstructing the subset in <code>O(n²)</code> time?</p>
