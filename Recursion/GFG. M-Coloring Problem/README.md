<h2>M-Coloring Problem</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an undirected graph and <code>m</code> colors, determine whether the graph can be colored such that no two adjacent vertices have the same color.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
V = 3
edges = [[0,1],[1,2],[0,2]]
m = 2

<strong>Output:</strong>
false </pre>

<p><strong>Approach:</strong></p>
<p>Use <strong>Backtracking</strong>. Assign a color to each vertex one by one. For every vertex, try all <code>m</code> colors and choose a color only if none of its adjacent vertices already has that color. If no color works, backtrack to the previous vertex and try another color.</p>

<p><strong>Key Observation:</strong></p>
<p>At every vertex there are at most <code>m</code> choices. If a choice makes the remaining graph impossible to color, undo it and try another color.</p>

<p><strong>Time Complexity:</strong> <code>O(m<sup>V</sup> × V)</code></p>

<p><strong>Space Complexity:</strong> <code>O(V)</code> for the color array and recursion stack.</p>
