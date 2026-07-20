<h2>Partition Into 2 Subsets with Min Sum Diff</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given an array <code>arr[]</code> containing <strong>non-negative integers</strong>, divide it into two subsets <code>set1</code> and <code>set2</code> such that the <strong>absolute difference</strong> between the sums of the two subsets is minimized.</p>

<p>Return the <strong>minimum possible difference</strong> between the sums of the two subsets.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [1, 6, 11, 5]

<strong>Output:</strong>
1

<strong>Explanation:</strong>

Subset1 = {1, 5, 6}
Sum = 12

Subset2 = {11}
Sum = 11

Minimum Difference = |12 - 11| = 1
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [1, 4]

<strong>Output:</strong>
3

<strong>Explanation:</strong>

Subset1 = {1}
Sum = 1

Subset2 = {4}
Sum = 4

Minimum Difference = |1 - 4| = 3
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [1]

<strong>Output:</strong>
1

<strong>Explanation:</strong>

Subset1 = {1}
Sum = 1

Subset2 = {}
Sum = 0

Minimum Difference = |1 - 0| = 1
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ arr.size() × (sum of array elements) ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ arr[i] ≤ 10<sup>5</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n × totalSum)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(totalSum)</code> <em>(optimized DP)</em></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> by computing all possible subset sums and minimizing <code>|totalSum - 2 × subsetSum|</code>, while optimizing the space complexity to <code>O(totalSum)</code>?</p>
