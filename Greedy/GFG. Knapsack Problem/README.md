<h2>Fractional Knapsack</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two arrays, <code>val[]</code> and <code>wt[]</code>, representing the values and weights of items, and an integer <code>capacity</code> representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack.</p>

<p>You are allowed to break items into fractions if necessary.</p>

<p>Return the maximum value as a <code>double</code>, rounded to <strong>6 decimal places</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong> val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
<strong>Output:</strong> 240.000000

<strong>Explanation:</strong>
Take the items with weights 10 and 20 completely, and 2/3 of the item
with weight 30.

Total value = 60 + 100 + (2/3 × 120) = 240.000000
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong> val[] = [500], wt[] = [30], capacity = 10
<strong>Output:</strong> 166.670000

<strong>Explanation:</strong>
Take 10/30 fraction of the item.

Value = (10/30 × 500) = 166.670000
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ val.size() = wt.size() ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ capacity ≤ 10<sup>9</sup></code></li>
  <li><code>1 ≤ val[i], wt[i] ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n log n)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(n)</code></p>
