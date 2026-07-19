<h2>64. Minimum Path Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an <code>m × n</code> grid filled with <strong>non-negative</strong> numbers, find a path from the <strong>top-left</strong> corner to the <strong>bottom-right</strong> corner that minimizes the sum of all numbers along its path.</p>

<p>You can only move in two directions:</p>

<ul>
  <li>Right</li>
  <li>Down</li>
</ul>

<p>Return the <strong>minimum path sum</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
grid =
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]

<strong>Output:</strong>
7

<strong>Explanation:</strong>

The path with the minimum sum is:

1 → 3 → 1 → 1 → 1

Total sum = 7.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
grid =
[
  [1,2,3],
  [4,5,6]
]

<strong>Output:</strong>
12

<strong>Explanation:</strong>

The minimum path is:

1 → 2 → 3 → 6

Total sum = 12.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == grid.length</code></li>
  <li><code>n == grid[i].length</code></li>
  <li><code>1 ≤ m, n ≤ 200</code></li>
  <li><code>0 ≤ grid[i][j] ≤ 200</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> in <code>O(m × n)</code> time while optimizing the space complexity to <code>O(n)</code>?</p>
