<h2>Undirected Graph Cycle</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an undirected graph with <code>V</code> vertices and <code>E</code> edges, represented as a 2D vector <code>edges[][]</code>, where each entry <code>edges[i] = [u, v]</code> denotes an edge between vertices <code>u</code> and <code>v</code>, determine whether the graph contains a cycle or not.</p>

<p><strong>Note:</strong> The graph can have multiple connected components.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 4, E = 4
edges[][] = [[0,1],[0,2],[1,2],[2,3]]

<strong>Output:</strong>
true

<strong>Explanation:</strong>
The graph contains the cycle:
1 → 2 → 0 → 1
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 4, E = 3
edges[][] = [[0,1],[1,2],[2,3]]

<strong>Output:</strong>
false

<strong>Explanation:</strong>
There is no cycle in the graph.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ V, E ≤ 10<sup>5</sup></code></li>
  <li><code>0 ≤ edges[i][0], edges[i][1] &lt; V</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(V + E)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V)</code></p>

<p><strong>Follow-up:</strong> Can you detect the cycle using either <strong>BFS</strong> (with parent tracking) or <strong>DFS</strong> efficiently?</p>
