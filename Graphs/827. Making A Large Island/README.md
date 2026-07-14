<h2>827. Making A Large Island</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>You are given an <code>n × n</code> binary matrix <code>grid</code>. You are allowed to change <strong>at most one</strong> <code>0</code> into a <code>1</code>.</p>

<p>Return the size of the <strong>largest island</strong> in the grid after applying this operation.</p>

<p>An <strong>island</strong> is a group of connected <code>1</code>s connected 4-directionally (up, down, left, or right).</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
grid = [[1,0],
        [0,1]]

<strong>Output:</strong>
3

<strong>Explanation:</strong>
Change one of the 0s to 1 and connect the two islands,
resulting in an island of size 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
grid = [[1,1],
        [1,0]]

<strong>Output:</strong>
4

<strong>Explanation:</strong>
Change the bottom-right 0 to 1 to make the entire grid one island.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
grid = [[1,1],
        [1,1]]

<strong>Output:</strong>
4

<strong>Explanation:</strong>
The grid already consists of a single island, so no change is needed.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n ≤ 500</code></li>
  <li><code>n == grid.length == grid[i].length</code></li>
  <li><code>grid[i][j]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using a <strong>Disjoint Set Union (Union-Find)</strong> or <strong>DFS</strong> to identify island sizes and evaluate the effect of flipping each <code>0</code>?</p>
