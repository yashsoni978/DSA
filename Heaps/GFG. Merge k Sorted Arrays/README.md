<h2>Merge k Sorted Arrays</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given a 2D matrix <code>mat[][]</code> of size <code>n × m</code>, where each row is sorted in <strong>non-decreasing order</strong>.</p>

<p>Your task is to merge all the rows into a single <strong>sorted array</strong> containing every element from the matrix.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
mat = [
  [1,3,5,7],
  [2,4,6,8],
  [0,9,10,11]
]

<strong>Output:</strong>
[0,1,2,3,4,5,6,7,8,9,10,11]

<strong>Explanation:</strong>

Merging the three sorted arrays
produces the final sorted array:

[0,1,2,3,4,5,6,7,8,9,10,11]
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
mat = [
  [1,2,3,4],
  [2,2,3,4],
  [5,5,6,6],
  [7,8,9,9]
]

<strong>Output:</strong>
[1,2,2,2,3,3,4,4,5,5,6,6,7,8,9,9]

<strong>Explanation:</strong>

After merging all four sorted arrays,
the resulting sorted array is:

[1,2,2,2,3,3,4,4,5,5,6,6,7,8,9,9]
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n × m ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ mat[i][j] ≤ 10<sup>6</sup></code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this efficiently using a <strong>Min Heap (Priority Queue)</strong> by storing the first element of each row and repeatedly extracting the smallest element, achieving <code>O(n × m × log n)</code> time and <code>O(n)</code> extra space?</p>
