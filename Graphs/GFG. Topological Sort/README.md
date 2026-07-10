<h2>Topological Sort</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a <strong>Directed Acyclic Graph (DAG)</strong> with <code>V</code> vertices (numbered from <code>0</code> to <code>V - 1</code>) and <code>E</code> edges represented as a 2D vector <code>edges[][]</code>, where each entry <code>edges[i] = [u, v]</code> denotes a directed edge from vertex <code>u</code> to vertex <code>v</code>, return a <strong>topological ordering</strong> of the vertices.</p>

<p>Topological sorting is a linear ordering of vertices such that for every directed edge <code>u → v</code>, vertex <code>u</code> appears before vertex <code>v</code> in the ordering.</p>

<p><strong>Note:</strong> Multiple valid topological orders may exist. Any valid ordering is accepted.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 4
E = 3
edges[][] = [[3,0],[1,0],[2,0]]

<strong>Output:</strong>
true

<strong>Explanation:</strong>
The output <code>true</code> indicates that the returned ordering is valid.

Some valid topological orders are:
[3,2,1,0]
[1,2,3,0]
[2,3,1,0]
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 6
E = 6
edges[][] = [[1,3],[2,3],[4,1],[4,0],[5,0],[5,2]]

<strong>Output:</strong>
true

<strong>Explanation:</strong>
The output <code>true</code> indicates that the returned ordering is valid.

Some valid topological orders are:
[4,5,0,1,2,3]
[5,2,4,0,1,3]
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 ≤ V ≤ 5 × 10<sup>3</sup></code></li>
  <li><code>1 ≤ E ≤ min(10<sup>5</sup>, (V × (V - 1)) / 2)</code></li>
  <li><code>0 ≤ edges[i][0], edges[i][1] &lt; V</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(V + E)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem using both <strong>Kahn's Algorithm (BFS)</strong> and <strong>DFS</strong>?</p>
