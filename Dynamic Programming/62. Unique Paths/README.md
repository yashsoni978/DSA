<h2>62. Unique Paths</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>There is a robot on an <code>m × n</code> grid. The robot is initially located at the <strong>top-left corner</strong> (i.e., <code>grid[0][0]</code>).</p>

<p>The robot tries to move to the <strong>bottom-right corner</strong> (i.e., <code>grid[m - 1][n - 1]</code>).</p>

<p>The robot can only move in two directions:</p>

<ul>
  <li>Down</li>
  <li>Right</li>
</ul>

<p>Given the two integers <code>m</code> and <code>n</code>, return the <strong>number of possible unique paths</strong> that the robot can take to reach the bottom-right corner.</p>

<p>The test cases are generated so that the answer will be less than or equal to <code>2 × 10<sup>9</sup></code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
m = 3, n = 7

<strong>Output:</strong>
28

<strong>Explanation:</strong>

There are 28 unique paths from the top-left
corner to the bottom-right corner.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
m = 3, n = 2

<strong>Output:</strong>
3

<strong>Explanation:</strong>

The possible paths are:

1. Right → Down → Down
2. Down → Down → Right
3. Down → Right → Down
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ m, n ≤ 100</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> with <code>O(m × n)</code> time and optimize the space complexity to <code>O(n)</code>?</p>
