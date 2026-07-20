<h2>Partitions with Given Difference</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>arr[]</code> and an integer <code>diff</code>, count the number of ways to partition the array into two subsets such that the <strong>difference between their sums</strong> is exactly <code>diff</code>.</p>

<p>A partition divides the array into two subsets <code>S1</code> and <code>S2</code> such that:</p>

<ul>
  <li>Every element belongs to exactly one subset.</li>
  <li><code>S1 ∪ S2</code> equals the original array.</li>
  <li><code>|sum(S1) - sum(S2)| = diff</code>.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [5, 2, 6, 4]
diff = 3

<strong>Output:</strong>
1

<strong>Explanation:</strong>

One valid partition is:

S1 = {6, 4}
S2 = {5, 2}

Difference = (6 + 4) - (5 + 2) = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [1, 1, 1, 1]
diff = 0

<strong>Output:</strong>
6

<strong>Explanation:</strong>

Choose any two 1's for the first subset,
and the remaining two form the second subset.

There are 6 such partitions.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [3, 2, 7, 1]
diff = 4

<strong>Output:</strong>
0

<strong>Explanation:</strong>

No partition satisfies the required difference.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ arr.size() ≤ 50</code></li>
  <li><code>0 ≤ diff ≤ 50</code></li>
  <li><code>0 ≤ arr[i] ≤ 6</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n × target)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(target)</code> <em>(optimized DP)</em></p>

<p><strong>Follow-up:</strong> Can you transform this into a <strong>Count Subsets with Sum</strong> problem using the relation <code>target = (totalSum - diff) / 2</code>, while correctly handling arrays containing <code>0</code>s?</p>
