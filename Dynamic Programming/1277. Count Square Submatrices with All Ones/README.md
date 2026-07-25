<h2>1277. Count Square Submatrices with All Ones</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an <code>m × n</code> binary matrix <code>matrix</code>, return the <strong>total number of square submatrices</strong> that contain <strong>only 1's</strong>.</p>

<p>A square submatrix can be of any size, as long as every element inside it is equal to <code>1</code>.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]

<strong>Output:</strong>
15

<strong>Explanation:</strong>

There are

10 squares of size 1 × 1
4 squares of size 2 × 2
1 square of size 3 × 3

Total = 15.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
matrix =
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]

<strong>Output:</strong>
7

<strong>Explanation:</strong>

There are

6 squares of size 1 × 1
1 square of size 2 × 2

Total = 7.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ matrix.length ≤ 300</code></li>
  <li><code>1 ≤ matrix[0].length ≤ 300</code></li>
  <li><code>0 ≤ matrix[i][j] ≤ 1</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> by letting <code>dp[i][j]</code> represent the side length of the largest square ending at cell <code>(i, j)</code>, where <code>dp[i][j] = 1 + min(top, left, top-left)</code> whenever <code>matrix[i][j] = 1</code>, achieving <code>O(m × n)</code> time and <code>O(m × n)</code> space (or <code>O(1)</code> extra space by modifying the input matrix)?</p>
