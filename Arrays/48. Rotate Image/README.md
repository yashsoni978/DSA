<h2>48. Rotate Image</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
You are given an <code>n x n</code> 2D matrix representing an image.
Rotate the image by <b>90 degrees clockwise</b>.
</p>

<p>
The rotation must be done <b>in-place</b>, meaning the input matrix should be
modified directly without using another matrix.
</p>

<h3>Example</h3>

<pre>
Input:
[
    [1,2,3],
    [4,5,6],
    [7,8,9]
]

Output:
[
    [7,4,1],
    [8,5,2],
    [9,6,3]
]
</pre>

<h3>Approach</h3>

<p>
We can rotate the matrix by performing two operations:
</p>

<ol>
<li><b>Transpose the matrix</b>.</li>
<li><b>Reverse every row</b>.</li>
</ol>

<h3>Step 1: Transpose</h3>

<p>
Transpose means converting rows into columns.
We swap <code>matrix[i][j]</code> with <code>matrix[j][i]</code>.
</p>

<pre>
Before:

1 2 3
4 5 6
7 8 9

After Transpose:

1 4 7
2 5 8
3 6 9
</pre>

<h3>Step 2: Reverse Every Row</h3>

<pre>
1 4 7  →  7 4 1
2 5 8  →  8 5 2
3 6 9  →  9 6 3
</pre>

<p>
Therefore, the final matrix is rotated by 90 degrees clockwise.
</p>

<h3>Why It Works</h3>

<p>
For a clockwise rotation:
</p>

<pre>
Transpose + Reverse each row
</pre>

<p>
For a 90-degree anticlockwise rotation, the opposite transformation can be used:
</p>

<pre>
Transpose + Reverse each column
</pre>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N²)
Space Complexity: O(1)
</pre>

<p>
We visit every element while transposing and reversing the rows.
No additional matrix is created, so the rotation is performed in-place.
</p>
