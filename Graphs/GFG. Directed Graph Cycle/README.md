<h2>Directed Graph Cycle</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a <strong>Directed Graph</strong> with <code>V</code> vertices (numbered from <code>0</code> to <code>V - 1</code>) and <code>E</code> edges, determine whether the graph contains a <strong>cycle</strong> or not.</p>

<p>The graph is represented as a 2D vector <code>edges[][]</code>, where each entry <code>edges[i] = [u, v]</code> denotes a directed edge from vertex <code>u</code> to vertex <code>v</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 4
edges[][] = [[0,1],[1,2],[2,0],[2,3]]

<strong>Output:</strong>
true

<strong>Explanation:</strong>
The graph contains the cycle:
0 → 1 → 2 → 0
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 4
edges[][] = [[0,1],[0,2],[1,2],[2,3]]

<strong>Output:</strong>
false

<strong>Explanation:</strong>
The graph does not contain any cycle.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ V ≤ 10<sup>5</sup></code></li>
  <li><code>0 ≤ E ≤ 10<sup>5</sup></code></li>
  <li><code>0 ≤ edges[i][0], edges[i][1] &lt; V</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(V + E)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V)</code></p>

<p><strong>Follow-up:</strong> Can you detect the cycle efficiently using <strong>DFS</strong> (visited + recursion stack) or <strong>Kahn's Algorithm (Topological Sort)</strong>?</p>
