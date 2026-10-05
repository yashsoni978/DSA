<h2>54. Spiral Matrix</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
Given an <code>m x n</code> matrix, return all the elements of the matrix
in spiral order.
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
[1,2,3,6,9,8,7,4,5]
</pre>

<h3>Approach</h3>

<p>
We use four boundaries to keep track of the unvisited portion of the matrix:
</p>

<ul>
<li><code>top</code> → topmost row</li>
<li><code>bottom</code> → bottommost row</li>
<li><code>left</code> → leftmost column</li>
<li><code>right</code> → rightmost column</li>
</ul>

<p>
We traverse the matrix in four directions:
</p>

<ol>
<li>Traverse the <b>top row</b> from left to right.</li>
<li>Traverse the <b>right column</b> from top to bottom.</li>
<li>Traverse the <b>bottom row</b> from right to left.</li>
<li>Traverse the <b>left column</b> from bottom to top.</li>
</ol>

<p>
After each traversal, move the corresponding boundary inward.
Continue until all elements have been visited.
</p>

<h3>Important Edge Cases</h3>

<p>
Before traversing the bottom row and left column, we must check whether
<code>top &lt;= bottom</code> and <code>left &lt;= right</code>.
This prevents duplicate elements when the matrix has only one row or one column
remaining.
</p>

<h3>Example</h3>

<pre>
[
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

Step 1 → Top row:
1 2 3

Step 2 → Right column:
6 9

Step 3 → Bottom row:
8 7

Step 4 → Left column:
4

Step 5 → Remaining element:
5

Result:
[1,2,3,6,9,8,7,4,5]
</pre>

<h3>Complexity</h3>

<pre>
Time Complexity: O(M × N)
Space Complexity: O(1) excluding the output
</pre>

<p>
Every matrix element is visited exactly once.
</p>
