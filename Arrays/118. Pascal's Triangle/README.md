<h2>118. Pascal's Triangle</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>
Given an integer <code>numRows</code>, return the first <code>numRows</code>
of Pascal's triangle.
</p>

<p>
In Pascal's triangle, every number is the sum of the two numbers directly
above it. The first and last elements of every row are always <code>1</code>.
</p>

<h3>Example</h3>

<pre>
Input:
numRows = 5

Output:
[
    [1],
    [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1]
]
</pre>

<h3>Approach</h3>

<p>
We build the triangle row by row.
</p>

<ol>
<li>Create a new row containing <code>row + 1</code> elements.</li>
<li>Set the first and last elements to <code>1</code>.</li>
<li>For every middle element, add the two elements from the previous row.</li>
<li>Add the current row to the answer.</li>
</ol>

<h3>How It Works</h3>

<pre>
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
</pre>

<p>
For example, in the fourth row:
</p>

<pre>
1  3  3  1

3 = 1 + 2
3 = 2 + 1
</pre>

<p>
So each middle element is calculated as:
</p>

<pre>
current[j] = previous[j-1] + previous[j]
</pre>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N²)
Space Complexity: O(N²)
</pre>

<p>
There are <code>N</code> rows and the total number of elements stored in
the triangle is <code>O(N²)</code>.
</p>
