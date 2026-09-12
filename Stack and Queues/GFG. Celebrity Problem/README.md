<h2>Celebrity Problem</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given a matrix where <code>mat[i][j] = 1</code> means person <code>i</code> knows person <code>j</code>, find the <strong>celebrity</strong>.</p>

<p>A celebrity:</p>
<ul>
<li>Is known by <strong>everyone else</strong>.</li>
<li>Does <strong>not know anyone else</strong>.</li>
</ul>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
mat = [[1,1,0],
       [0,1,0],
       [0,1,1]]

<strong>Output:</strong>
1 </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Use the <strong>Two-Pointer Elimination</strong> technique.</p>

<ul>
<li>Start with <code>candidate = 0</code>.</li>
<li>For every person <code>i</code>, if <code>candidate</code> knows <code>i</code>, then candidate cannot be the celebrity, so set <code>candidate = i</code>.</li>
<li>After finding a candidate, <strong>verify</strong> that everyone knows the candidate and the candidate knows nobody.</li>
</ul>

<pre>
if(mat[candidate][i] == 1)
    candidate = i;
</pre>

<p><strong>Key Observation:</strong></p>
<p>If <code>A</code> knows <code>B</code>, then <code>A</code> cannot be the celebrity. Therefore, eliminate <code>A</code> and continue with <code>B</code>.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>
<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
