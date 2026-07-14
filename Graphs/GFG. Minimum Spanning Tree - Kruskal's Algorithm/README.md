<h2>Minimum Spanning Tree - Kruskal's Algorithm</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a weighted, undirected, and connected graph with <code>V</code> vertices and <code>E</code> edges, your task is to find the sum of the weights of the edges in the <strong>Minimum Spanning Tree (MST)</strong> of the graph using <strong>Kruskal's Algorithm</strong>.</p>

<p>The graph is represented as an edge list <code>edges[][]</code>, where <code>edges[i] = [u, v, w]</code> denotes an undirected edge between vertices <code>u</code> and <code>v</code> with weight <code>w</code>.</p>

<p>Return the total weight of the Minimum Spanning Tree.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 3
E = 3
edges[][] = [[0,1,5],[1,2,3],[0,2,1]]

<strong>Output:</strong>
4

<strong>Explanation:</strong>

The Minimum Spanning Tree consists of the edges:

0 → 2 (weight = 1)
1 → 2 (weight = 3)

Total MST weight = 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 2
E = 1
edges[][] = [[0,1,5]]

<strong>Output:</strong>
5

<strong>Explanation:</strong>

Only one spanning tree is possible, so its total weight is 5.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 ≤ V ≤ 1000</code></li>
  <li><code>V - 1 ≤ E ≤ (V × (V - 1)) / 2</code></li>
  <li><code>1 ≤ w ≤ 1000</code></li>
  <li>The graph is connected.</li>
  <li>The graph contains no self-loops or multiple edges.</li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(E log E)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V)</code></p>

<p><strong>Follow-up:</strong> Can you implement <strong>Kruskal's Algorithm</strong> efficiently using a <strong>Disjoint Set Union (Union-Find)</strong> data structure with <strong>Path Compression</strong> and <strong>Union by Rank/Size</strong>?</p>
