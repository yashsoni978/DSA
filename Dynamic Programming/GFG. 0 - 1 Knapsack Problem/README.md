<h2>0 - 1 Knapsack Problem</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two arrays <code>val[]</code> and <code>wt[]</code>, where <code>val[i]</code> represents the value of the <code>i<sup>th</sup></code> item and <code>wt[i]</code> represents its weight, along with an integer <code>W</code> denoting the maximum capacity of the knapsack.</p>

<p>Select a subset of the items such that:</p>

<ul>
  <li>The total weight does not exceed <code>W</code>.</li>
  <li>The total value is maximized.</li>
</ul>

<p><strong>Note:</strong> Each item can either be <strong>included entirely</strong> or <strong>excluded entirely</strong>. Fractional selection is <strong>not allowed</strong>, and each item can be chosen at most once.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
W = 4
val[] = [1, 2, 3]
wt[] = [4, 5, 1]

<strong>Output:</strong>
3

<strong>Explanation:</strong>

Choose the third item.

Weight = 1
Value = 3

Maximum obtainable value = 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
W = 3
val[] = [1, 2, 3]
wt[] = [4, 5, 6]

<strong>Output:</strong>
0

<strong>Explanation:</strong>

Every item's weight exceeds the
knapsack capacity, so no item can be selected.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
W = 5
val[] = [10, 40, 30, 50]
wt[] = [5, 4, 2, 3]

<strong>Output:</strong>
80

<strong>Explanation:</strong>

Choose:

Item 3 → Value = 30, Weight = 2
Item 4 → Value = 50, Weight = 3

Total Weight = 5
Total Value = 80
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ val.size() = wt.size() ≤ 10<sup>3</sup></code></li>
  <li><code>1 ≤ W ≤ 10<sup>3</sup></code></li>
  <li><code>1 ≤ val[i] ≤ 10<sup>3</sup></code></li>
  <li><code>1 ≤ wt[i] ≤ 10<sup>3</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n × W)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(W)</code> <em>(optimized DP)</em></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> by optimizing the classic <code>O(n × W)</code> DP table into a single <code>O(W)</code> array while ensuring each item is used at most once?</p>
