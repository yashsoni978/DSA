<h2>994. Rotting Oranges</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an <code>m x n</code> grid where each cell can have one of three values:</p>

<ul>
  <li><code>0</code> representing an empty cell.</li>
  <li><code>1</code> representing a fresh orange.</li>
  <li><code>2</code> representing a rotten orange.</li>
</ul>

<p>Every minute, any fresh orange that is <strong>4-directionally adjacent</strong> (up, down, left, or right) to a rotten orange becomes rotten.</p>

<p>Return <em>the minimum number of minutes that must elapse until no cell has a fresh orange</em>. If this is impossible, return <code>-1</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
grid = [[2,1,1],[1,1,0],[0,1,1]]

<strong>Output:</strong>
4
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
grid = [[2,1,1],[0,1,1],[1,0,1]]

<strong>Output:</strong>
-1

<strong>Explanation:</strong>
The orange in the bottom-left corner can never rot because rotting only spreads
4-directionally.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
grid = [[0,2]]

<strong>Output:</strong>
0

<strong>Explanation:</strong>
Since there are no fresh oranges at minute 0, the answer is just 0.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == grid.length</code></li>
  <li><code>n == grid[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 10</code></li>
  <li><code>grid[i][j]</code> is <code>0</code>, <code>1</code>, or <code>2</code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using <strong>Multi-Source BFS</strong>?</p>
