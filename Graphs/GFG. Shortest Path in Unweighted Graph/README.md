<h2>Shortest Path in Directed Acyclic Graph</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a <strong>Directed Acyclic Graph (DAG)</strong> with <code>V</code> vertices numbered from <code>0</code> to <code>V - 1</code> and a 2D integer array <code>edges[][]</code> of length <code>E</code>, where each entry <code>edges[i] = [u, v, w]</code> represents a directed edge from vertex <code>u</code> to vertex <code>v</code> with weight <code>w</code>.</p>

<p>Find the shortest distance from the source vertex <code>0</code> to every other vertex. If a vertex is unreachable from the source, return <code>-1</code> for that vertex.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 4
E = 2
edges = [[0,1,2],[0,2,1]]

<strong>Output:</strong>
[0,2,1,-1]

<strong>Explanation:</strong>
Shortest path from 0 to 1 is 0 → 1 with cost 2.
Shortest path from 0 to 2 is 0 → 2 with cost 1.
Vertex 3 is unreachable, so its distance is -1.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 6
E = 7
edges = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]

<strong>Output:</strong>
[0,2,3,6,1,5]

<strong>Explanation:</strong>
Shortest path from 0 to 1 is 0 → 1 with cost 2.
Shortest path from 0 to 2 is 0 → 4 → 2 with cost 3.
Shortest path from 0 to 3 is 0 → 4 → 5 → 3 with cost 6.
Shortest path from 0 to 4 is 0 → 4 with cost 1.
Shortest path from 0 to 5 is 0 → 4 → 5 with cost 5.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ V ≤ 100</code></li>
  <li><code>1 ≤ E ≤ min((V × (V - 1)) / 2, 4000)</code></li>
  <li><code>0 ≤ edges[i][0], edges[i][1] &lt; V</code></li>
  <li><code>0 ≤ edges[i][2] ≤ 10<sup>5</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(V + E)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V + E)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently by first performing a <strong>Topological Sort</strong> and then relaxing the edges in topological order?</p>
