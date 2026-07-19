<h2>63. Unique Paths II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an <code>m × n</code> integer array <code>obstacleGrid</code>. There is a robot initially located at the <strong>top-left corner</strong> (i.e., <code>obstacleGrid[0][0]</code>).</p>

<p>The robot tries to move to the <strong>bottom-right corner</strong> (i.e., <code>obstacleGrid[m - 1][n - 1]</code>).</p>

<p>The robot can only move in two directions:</p>

<ul>
  <li>Right</li>
  <li>Down</li>
</ul>

<p>An obstacle and empty space are marked as follows:</p>

<ul>
  <li><code>0</code> → Empty cell</li>
  <li><code>1</code> → Obstacle</li>
</ul>

<p>The robot cannot move onto or through a cell containing an obstacle.</p>

<p>Return the <strong>number of unique paths</strong> the robot can take to reach the bottom-right corner.</p>

<p>The answer is guaranteed to be less than or equal to <code>2 × 10<sup>9</sup></code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
obstacleGrid =
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

<strong>Output:</strong>
2

<strong>Explanation:</strong>

There is one obstacle in the middle of the grid.

The robot can reach the destination using only
the following two paths:

1. Right → Right → Down → Down
2. Down → Down → Right → Right
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
obstacleGrid =
[
  [0,1],
  [0,0]
]

<strong>Output:</strong>
1
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == obstacleGrid.length</code></li>
  <li><code>n == obstacleGrid[i].length</code></li>
  <li><code>1 ≤ m, n ≤ 100</code></li>
  <li><code>obstacleGrid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> with <code>O(m × n)</code> time and optimize the space complexity to <code>O(n)</code>?</p>
