<h2>Matrix Chain Multiplication</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given an array <code>arr[]</code> representing the dimensions of a sequence of matrices, where the <code>i<sup>th</sup></code> matrix has dimensions <code>(arr[i-1] × arr[i])</code> for <code>i ≥ 1</code>, determine the <strong>minimum number of scalar multiplications</strong> needed to multiply the entire chain of matrices.</p>

<p>The order in which the matrices are multiplied affects the total number of scalar multiplications, even though the final result remains the same.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [2, 1, 3, 4]

<strong>Output:</strong>
20

<strong>Explanation:</strong>

There are three matrices:

M1 = 2 × 1
M2 = 1 × 3
M3 = 3 × 4

Two possible parenthesizations are:

((M1 × M2) × M3)
Cost = (2 × 1 × 3) + (2 × 3 × 4)
     = 6 + 24 = 30

(M1 × (M2 × M3))
Cost = (1 × 3 × 4) + (2 × 1 × 4)
     = 12 + 8 = 20

Minimum cost = 20.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [1, 2, 3, 4, 3]

<strong>Output:</strong>
30

<strong>Explanation:</strong>

There are four matrices:

M1 = 1 × 2
M2 = 2 × 3
M3 = 3 × 4
M4 = 4 × 3

The optimal parenthesization is

(((M1 × M2) × M3) × M4)

Cost = (1 × 2 × 3)
     + (1 × 3 × 4)
     + (1 × 4 × 3)
     = 6 + 12 + 12
     = 30
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
arr[] = [3, 4]

<strong>Output:</strong>
0

<strong>Explanation:</strong>

Only one matrix exists.

Hence no multiplication
is required.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 ≤ arr.size() ≤ 100</code></li>
  <li><code>1 ≤ arr[i] ≤ 200</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n³)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(n²)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Interval Dynamic Programming</strong>, where <code>dp[i][j]</code> represents the minimum multiplication cost for multiplying matrices from <code>i</code> to <code>j</code>, considering every possible partition point <code>k</code>?</p>
