<h2>2643. Row With Maximum Ones</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Given a binary matrix <code>mat</code>, find the <strong>row index</strong> containing the maximum number of <code>1</code>s and return the row index along with the count of <code>1</code>s.</p>

<p>If multiple rows have the same maximum number of <code>1</code>s, return the row with the <strong>smallest index</strong>. :contentReference[oaicite:0]{index=0}</p>

<h3>Example 1</h3>

<pre>
Input: mat = [[0,1],[1,0]]

Output: [0,1]
</pre>

<h3>Example 2</h3>

<pre>
Input: mat = [[0,0,0],[0,1,1]]

Output: [1,2]
</pre>

<h3>Approach</h3>

<ul>
<li>Traverse every row of the matrix.</li>
<li>For each row, count the number of <code>1</code>s.</li>
<li>Maintain the maximum number of <code>1</code>s found so far and its row index.</li>
<li>Update the answer only when the current count is <strong>greater</strong> than the maximum.</li>
<li>Using <code>&gt;</code> instead of <code>&gt;=</code> automatically keeps the smallest row index when there is a tie.</li>
</ul>

<h3>Why This Works</h3>

<p>Every element of the matrix is checked exactly once. Since the matrix contains only <code>0</code> and <code>1</code>, we can directly count the <code>1</code>s in each row and keep the best row.</p>

<pre>
Row 0 → 2 ones
Row 1 → 4 ones  ← maximum
Row 2 → 1 one

Answer = [1, 4]
</pre>

<h3>Important Concept</h3>

<p>When two rows have the same number of <code>1</code>s, do not update the answer:</p>

<pre>
if(currentOnes &gt; maxOnes)
</pre>

<p>This ensures the first row with the maximum count is retained.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(m × n)</code></p>

<p>Every element in the matrix is visited once.</p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<p>Only variables for the maximum count and row index are used. :contentReference[oaicite:1]{index=1}</p>

<hr>

<p><strong>Pattern:</strong> Matrix Traversal / Array / Counting</p>

<p><strong>Key Idea:</strong> Count the number of <code>1</code>s in every row and keep track of the row with the maximum count. Use a strict <code>&gt;</code> comparison so that the smallest row index is retained in case of a tie.</p>
