<h2>1091. Shortest Path in Binary Matrix</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an <code>n × n</code> binary matrix <code>grid</code>, return the length of the <strong>shortest clear path</strong> in the matrix. If no such path exists, return <code>-1</code>.</p>

<p>A <strong>clear path</strong> is a path from the <strong>top-left</strong> cell <code>(0, 0)</code> to the <strong>bottom-right</strong> cell <code>(n - 1, n - 1)</code> such that:</p>

<ul>
  <li>All visited cells have value <code>0</code>.</li>
  <li>All adjacent cells in the path are <strong>8-directionally connected</strong> (horizontal, vertical, or diagonal).</li>
  <li>The length of a clear path is the number of visited cells.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
grid = [[0,1],[1,0]]

<strong>Output:</strong>
2

<strong>Explanation:</strong>
The shortest clear path is:
(0,0) → (1,1)
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
grid = [[0,0,0],[1,1,0],[1,1,0]]

<strong>Output:</strong>
4

<strong>Explanation:</strong>
One shortest clear path is:
(0,0) → (0,1) → (1,2) → (2,2)
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
grid = [[1,0,0],[1,1,0],[1,1,0]]

<strong>Output:</strong>
-1

<strong>Explanation:</strong>
The starting cell is blocked, so no clear path exists.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == grid.length</code></li>
  <li><code>n == grid[i].length</code></li>
  <li><code>1 ≤ n ≤ 100</code></li>
  <li><code>grid[i][j]</code> is <code>0</code> or <code>1</code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using <strong>Breadth-First Search (BFS)</strong> with <strong>8-directional traversal</strong> in <code>O(n²)</code> time?</p>
