<h2>1s Surrounded by 0s</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an <code>n × m</code> binary matrix <code>grid[][]</code>, find the total count of all cells containing <code>1</code> that are unable to move out of the grid through a path of adjacent <code>1</code>s.</p>

<p>Adjacency means you can only move in four directions: <strong>Up, Down, Left,</strong> and <strong>Right</strong>. Diagonal moves are not allowed.</p>

<p>Assume that the space immediately outside the grid is an open path. Any <code>1</code> located directly on the outer boundary of the grid (first row, last row, first column, or last column) can immediately step out, and any <code>1</code> connected to it can also step out of the grid.</p>

<p>Return the total number of <code>1</code>s that are completely enclosed by <code>0</code>s.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
grid = [
  [0,0,0,0],
  [1,0,1,0],
  [0,1,1,0],
  [0,0,0,0]
]

<strong>Output:</strong>
3
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
grid = [
  [1,1,0,0,0,1],
  [0,1,1,0,1,0],
  [0,0,0,1,1,0],
  [0,0,0,1,1,0],
  [0,1,0,1,0,0],
  [1,1,0,0,0,1]
]

<strong>Output:</strong>
6
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n, m ≤ 500</code></li>
  <li><code>0 ≤ grid[i][j] ≤ 1</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n × m)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(n × m)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using <strong>DFS</strong> or <strong>BFS</strong> by first marking all boundary-connected <code>1</code>s?</p>
