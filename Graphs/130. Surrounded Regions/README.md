<h2>130. Surrounded Regions</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an <code>m x n</code> matrix <code>board</code> containing letters <code>'X'</code> and <code>'O'</code>. Capture all regions that are <strong>4-directionally surrounded</strong> by <code>'X'</code>.</p>

<p>A region is captured by flipping all <code>'O'</code>s into <code>'X'</code>s in that surrounded region.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
board = [
  ["X","X","X","X"],
  ["X","O","O","X"],
  ["X","X","O","X"],
  ["X","O","X","X"]
]

<strong>Output:</strong>
[
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","X","X","X"],
  ["X","O","X","X"]
]

<strong>Explanation:</strong>
The bottom <code>'O'</code> is not flipped because it is connected to the border.
All other <code>'O'</code>s are surrounded by <code>'X'</code> and are flipped.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
board = [["X"]]

<strong>Output:</strong>
[["X"]]
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>m == board.length</code></li>
  <li><code>n == board[i].length</code></li>
  <li><code>1 &lt;= m, n &lt;= 200</code></li>
  <li><code>board[i][j]</code> is either <code>'X'</code> or <code>'O'</code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>DFS</strong> or <strong>BFS</strong> without using extra space for another board?</p>
