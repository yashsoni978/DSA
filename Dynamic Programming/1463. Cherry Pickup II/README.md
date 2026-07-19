<h2>1463. Cherry Pickup II</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>You are given a <code>rows × cols</code> matrix <code>grid</code> representing the number of cherries in each cell.</p>

<p>Two robots start collecting cherries simultaneously:</p>

<ul>
  <li><strong>Robot 1</strong> starts at the top-left corner: <code>(0, 0)</code>.</li>
  <li><strong>Robot 2</strong> starts at the top-right corner: <code>(0, cols - 1)</code>.</li>
</ul>

<p>Both robots move from the first row to the last row. From a cell <code>(r, c)</code>, each robot may move to one of the following positions in the next row:</p>

<ul>
  <li><code>(r + 1, c - 1)</code></li>
  <li><code>(r + 1, c)</code></li>
  <li><code>(r + 1, c + 1)</code></li>
</ul>

<p>When a robot visits a cell, it collects all cherries from that cell. If both robots land on the <strong>same cell</strong>, the cherries are counted <strong>only once</strong>.</p>

<p>Return the <strong>maximum number of cherries</strong> both robots can collect.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
grid =
[
  [3,1,1],
  [2,5,1],
  [1,5,5],
  [2,1,1]
]

<strong>Output:</strong>
24

<strong>Explanation:</strong>

One optimal path is:

Robot 1: (0,0) → (1,0) → (2,1) → (3,0)
Robot 2: (0,2) → (1,1) → (2,2) → (3,2)

Total cherries collected = 24.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
grid =
[
  [1,0,0,0,0,0,1],
  [2,0,0,0,0,3,0],
  [2,0,9,0,0,0,0],
  [0,3,0,5,4,0,0],
  [1,0,2,3,0,0,6]
]

<strong>Output:</strong>
28
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>rows == grid.length</code></li>
  <li><code>cols == grid[i].length</code></li>
  <li><code>2 ≤ rows, cols ≤ 70</code></li>
  <li><code>0 ≤ grid[i][j] ≤ 100</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>3D Dynamic Programming</strong> in <code>O(rows × cols² × 9)</code> time and optimize the space complexity from <code>O(rows × cols²)</code> to <code>O(cols²)</code>?</p>
