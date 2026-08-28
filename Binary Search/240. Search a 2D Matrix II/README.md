<h2>240. Search a 2D Matrix II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an <strong>m × n</strong> matrix where each row and each column is sorted in ascending order, determine whether a given <code>target</code> exists in the matrix.</p>

<h3>Example 1</h3>

<pre>
Input: matrix = [[1,4,7,11,15],
                 [2,5,8,12,19],
                 [3,6,9,16,22],
                 [10,13,14,17,24],
                 [18,21,23,26,30]], target = 5

Output: true
</pre>

<h3>Example 2</h3>

<pre>
Input: matrix = [[1,4,7,11,15],
                 [2,5,8,12,19],
                 [3,6,9,16,22],
                 [10,13,14,17,24],
                 [18,21,23,26,30]], target = 20

Output: false
</pre>

<h3>Approach</h3>

<ul>
<li>Start from the <strong>top-right corner</strong> of the matrix.</li>
<li>If the current element equals <code>target</code>, return <code>true</code>.</li>
<li>If the current element is greater than <code>target</code>, move <strong>left</strong>.</li>
<li>If the current element is smaller than <code>target</code>, move <strong>down</strong>.</li>
<li>Continue until the target is found or we move outside the matrix.</li>
</ul>

<h3>Why This Works</h3>

<p>From the top-right corner:</p>

<pre>
        smaller ← ← ←
                  ↑
                  |
                larger
                  |
                  ↓
</pre>

<p>If the current value is too large, everything below it in that column is also too large, so we can eliminate the column by moving left.</p>

<p>If the current value is too small, everything to its left in that row is also too small, so we can eliminate the row by moving down.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(m + n)</code></p>

<p>At every step, either the row or column is eliminated.</p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<p>Only row and column pointers are used.</p>

<hr>

<p><strong>Pattern:</strong> Matrix / Two Pointer / Staircase Search</p>

<p><strong>Key Idea:</strong> Start from the top-right corner. Move left when the current value is greater than the target and move down when it is smaller. This eliminates one row or column at every step.</p>
