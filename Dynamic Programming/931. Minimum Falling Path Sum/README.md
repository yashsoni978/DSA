<h2>931. Minimum Falling Path Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an <code>n × n</code> array of integers <code>matrix</code>, return the <strong>minimum sum</strong> of any <strong>falling path</strong> through the matrix.</p>

<p>A <strong>falling path</strong> starts at any element in the <strong>first row</strong> and chooses one element from each row. The next row's choice must be in one of the following columns:</p>

<ul>
  <li>Directly below: <code>(row + 1, col)</code></li>
  <li>Diagonally left: <code>(row + 1, col - 1)</code></li>
  <li>Diagonally right: <code>(row + 1, col + 1)</code></li>
</ul>

<p>Return the minimum possible sum of a falling path.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
matrix =
[
  [2,1,3],
  [6,5,4],
  [7,8,9]
]

<strong>Output:</strong>
13

<strong>Explanation:</strong>

The minimum falling path is:

1 → 4 → 8

Total sum = 13.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
matrix =
[
  [-19,57],
  [-40,-5]
]

<strong>Output:</strong>
-59

<strong>Explanation:</strong>

The minimum falling path is:

-19 → -40

Total sum = -59.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == matrix.length == matrix[i].length</code></li>
  <li><code>1 ≤ n ≤ 100</code></li>
  <li><code>-100 ≤ matrix[i][j] ≤ 100</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> in <code>O(n²)</code> time while optimizing the extra space complexity to <code>O(n)</code>?</p>
