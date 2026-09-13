<h2>51. N-Queens</h2>
<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>
<hr>

<p>Place <code>n</code> queens on an <code>n × n</code> chessboard so that no two queens attack each other.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
n = 4

<strong>Output:</strong>
[[".Q..","...Q","Q...","..Q."],
["..Q.","Q...","...Q",".Q.."]] </pre>

<p><strong>Approach:</strong></p>
<p>Use <strong>Backtracking</strong>. Place one queen in each row and try every column. A position is valid only if no queen exists in the same column, upper-left diagonal, or upper-right diagonal. If a placement leads to a dead end, backtrack and try another column.</p>

<p><strong>Key Observation:</strong></p>
<p>Since we place exactly one queen per row, we only need to check <strong>columns and diagonals</strong>. Backtracking explores all possible placements while abandoning invalid paths early.</p>

<p><strong>Time Complexity:</strong> <code>O(n!)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code> excluding the output.</p>
