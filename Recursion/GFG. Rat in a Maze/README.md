<h2>Rat in a Maze</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an <code>n × n</code> binary matrix, find all paths for a rat to move from <code>(0,0)</code> to <code>(n-1,n-1)</code>. The rat can move <code>U</code>, <code>D</code>, <code>L</code>, or <code>R</code> and cannot visit a cell more than once.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
maze = [[1,0,0,0],
        [1,1,0,1],
        [1,1,0,0],
        [0,1,1,1]]

<strong>Output:</strong>
["DDRDRR","DRDDRR"] </pre>

<p><strong>Approach:</strong></p>
<p>Use <strong>Backtracking</strong>. Starting from <code>(0,0)</code>, try all four possible directions. Move only to a valid, unvisited open cell. Add the direction to the current path and recursively continue. If the path does not work, undo the move and try another direction.</p>

<p><strong>Key Observation:</strong></p>
<p>Mark the current cell as <strong>visited</strong> before exploring and unmark it while backtracking. This prevents cycles while allowing the cell to be used in a different path.</p>

<p><strong>Time Complexity:</strong> <code>O(4<sup>n²</sup>)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n²)</code> for the visited matrix and recursion stack, excluding the output.</p>
