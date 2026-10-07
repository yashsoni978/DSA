<h2>73. Set Matrix Zeroes</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
Given an <code>m x n</code> integer matrix, if an element is <code>0</code>,
set its entire row and column to <code>0</code>.
The operation must be done <b>in-place</b>.
</p>

<h3>Example</h3>

<pre>
Input:
[
    [1,1,1],
    [1,0,1],
    [1,1,1]
]

Output:
[
    [1,0,1],
    [0,0,0],
    [1,0,1]
]
</pre>

<h3>Approach</h3>

<p>
We use the <b>first row and first column as markers</b> to achieve
constant extra space.
</p>

<ol>
<li>Check whether the first row contains a zero.</li>
<li>Check whether the first column contains a zero.</li>
<li>Traverse the remaining matrix.</li>
<li>If <code>matrix[i][j] == 0</code>, mark its row and column:
    <pre>matrix[i][0] = 0;
matrix[0][j] = 0;</pre>
</li>
<li>Traverse the remaining matrix again and set <code>matrix[i][j] = 0</code>
if its row or column has been marked.</li>
<li>Finally, set the first row and first column to zero if they originally
contained a zero.</li>
</ol>

<h3>Why Do We Need Extra Variables?</h3>

<p>
The first row and first column are themselves used as markers.
Therefore, we need two boolean variables to remember whether they originally
contained a zero.
</p>

<pre>
rowZero = first row contains 0
colZero = first column contains 0
</pre>

<h3>Example</h3>

<pre>
Input:

1 1 1
1 0 1
1 1 1

After marking:

1 0 1
0 0 1
1 1 1

Using the markers:

1 0 1
0 0 0
1 0 1
</pre>

<h3>Important Point</h3>

<p>
We should not immediately convert rows and columns to zero while scanning,
because those newly created zeros would incorrectly affect other rows and
columns.
</p>

<p>
Instead, we first <b>mark</b> the affected rows and columns and then perform
the zeroing operation.
</p>

<h3>Complexity</h3>

<pre>
Time Complexity: O(M × N)
Space Complexity: O(1)
</pre>

<p>
The matrix is traversed a constant number of times, and no additional
row/column arrays are used.
</p>
