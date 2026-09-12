<h2>85. Maximal Rectangle</h2>
<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>
<hr>

<p>Given a binary matrix, find the area of the <strong>largest rectangle containing only 1's</strong>.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
matrix = [
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]

<strong>Output:</strong>
6 </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Convert each row into a <strong>Histogram</strong> and use <strong>Largest Rectangle in Histogram (84)</strong>.</p>

<ul>
<li>Maintain <code>heights[j]</code> = consecutive number of <code>1's</code> in column <code>j</code>.</li>
<li>If <code>matrix[i][j] == '1'</code>, increment <code>heights[j]</code>.</li>
<li>If it is <code>'0'</code>, reset <code>heights[j] = 0</code>.</li>
<li>For every row, calculate the largest histogram rectangle.</li>
</ul>

<pre>
Row → Histogram → Largest Rectangle
</pre>

<p><strong>Key Observation:</strong></p>
<p>Every row can be treated as the base of a histogram. Therefore, the problem reduces to repeatedly solving <strong>Largest Rectangle in Histogram</strong>.</p>

<p><strong>Time Complexity:</strong> <code>O(rows × cols)</code></p>
<p><strong>Space Complexity:</strong> <code>O(cols)</code></p>
