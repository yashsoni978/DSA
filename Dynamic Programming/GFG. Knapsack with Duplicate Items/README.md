<h2>Knapsack with Duplicate Items</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two arrays <code>val[]</code> and <code>wt[]</code>, where <code>val[i]</code> represents the value of the <code>i<sup>th</sup></code> item and <code>wt[i]</code> represents its weight, along with an integer <code>capacity</code> representing the maximum weight the knapsack can hold.</p>

<p>Your task is to maximize the total value that can be obtained without exceeding the given capacity.</p>

<p><strong>Note:</strong> Unlike the 0-1 Knapsack problem, <strong>each item can be chosen an unlimited number of times</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
val[] = [1, 1]
wt[] = [2, 1]
capacity = 3

<strong>Output:</strong>
3

<strong>Explanation:</strong>

Choose the 2nd item three times.

Total Weight = 1 + 1 + 1 = 3
Total Value = 1 + 1 + 1 = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
val[] = [10, 40, 50, 70]
wt[] = [1, 3, 4, 5]
capacity = 8

<strong>Output:</strong>
110

<strong>Explanation:</strong>

Choose:

Item 2 → Value = 40, Weight = 3
Item 4 → Value = 70, Weight = 5

Total Weight = 8
Total Value = 110
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
val[] = [6, 8, 7, 100]
wt[] = [2, 3, 4, 5]
capacity = 1

<strong>Output:</strong>
0

<strong>Explanation:</strong>

No item can fit into the knapsack,
so the maximum obtainable value is 0.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ val.size() = wt.size() ≤ 1000</code></li>
  <li><code>1 ≤ capacity ≤ 1000</code></li>
  <li><code>1 ≤ val[i], wt[i] ≤ 100</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n × capacity)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(capacity)</code> <em>(optimized DP)</em></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Unbounded Knapsack Dynamic Programming</strong> by allowing repeated selection of the same item while optimizing the space complexity to <code>O(capacity)</code>?</p>
