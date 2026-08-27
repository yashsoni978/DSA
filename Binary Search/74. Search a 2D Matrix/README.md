<h2>74. Search a 2D Matrix</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an <strong>m × n</strong> matrix where each row is sorted in ascending order and the first element of each row is greater than the last element of the previous row, determine whether a given <code>target</code> exists in the matrix.</p>

<h3>Example 1</h3>

<pre>
Input: matrix = [[1,3,5,7],
                 [10,11,16,20],
                 [23,30,34,60]], target = 3

Output: true
</pre>

<h3>Example 2</h3>

<pre>
Input: matrix = [[1,3,5,7],
                 [10,11,16,20],
                 [23,30,34,60]], target = 13

Output: false
</pre>

<h3>Approach</h3>

<ul>
<li>Since the entire matrix behaves like one sorted array, use <strong>Binary Search</strong>.</li>
<li>Treat the matrix as a virtual 1D array of size <code>m × n</code>.</li>
<li>For a 1D index <code>mid</code>, convert it into matrix coordinates:</li>
</ul>

<pre>
row = mid / n
col = mid % n
</pre>

<ul>
<li>If <code>matrix[row][col] == target</code>, return <code>true</code>.</li>
<li>If the current value is smaller than <code>target</code>, search right.</li>
<li>Otherwise, search left.</li>
</ul>

<h3>Why Binary Search Works</h3>

<p>The matrix satisfies two conditions:</p>

<pre>
Each row is sorted.

First element of current row
&gt; last element of previous row.
</pre>

<p>Therefore, if the matrix is viewed as a single array, all elements are sorted:</p>

<pre>
[1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60]
</pre>

<p>This allows normal binary search to be applied.</p>

<h3>Index Conversion</h3>

<p>For a matrix with <code>n</code> columns:</p>

<pre>
row = mid / n
col = mid % n
</pre>

<p>For example, if <code>n = 4</code> and <code>mid = 6</code>:</p>

<pre>
row = 6 / 4 = 1
col = 6 % 4 = 2

matrix[1][2]
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(log(m × n))</code></p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / 2D Matrix / Flattened Binary Search</p>

<p><strong>Key Idea:</strong> Treat the sorted 2D matrix as a virtual 1D sorted array and use binary search. Convert each 1D index into a matrix row and column using <code>row = mid / n</code> and <code>col = mid % n</code>.</p>
