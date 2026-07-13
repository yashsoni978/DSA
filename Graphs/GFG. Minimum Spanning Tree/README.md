<h2>Minimum Spanning Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a weighted, undirected, and connected graph with <code>V</code> vertices and <code>E</code> edges, your task is to find the sum of the weights of the edges in the <strong>Minimum Spanning Tree (MST)</strong> of the graph.</p>

<p>The graph is represented as a list of edges, where each edge is given as <code>[u, v, w]</code>, indicating an undirected edge between vertices <code>u</code> and <code>v</code> with weight <code>w</code>.</p>

<p>Return the total weight of the Minimum Spanning Tree.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 3
E = 3
Edges = [[0,1,5],[1,2,3],[0,2,1]]

<strong>Output:</strong>
4

<strong>Explanation:</strong>
The Minimum Spanning Tree consists of the edges:
0 → 2 (weight = 1)
1 → 2 (weight = 3)

Total weight = 1 + 3 = 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 2
E = 1
Edges = [[0,1,5]]

<strong>Output:</strong>
5

<strong>Explanation:</strong>
Only one spanning tree is possible, with total weight 5.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 ≤ V ≤ 1000</code></li>
  <li><code>V - 1 ≤ E ≤ (V × (V - 1)) / 2</code></li>
  <li><code>1 ≤ w ≤ 1000</code></li>
  <li>The graph is connected.</li>
  <li>The graph contains no self-loops or multiple edges.</li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(E log V)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V + E)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem using either <strong>Prim's Algorithm</strong> (Min Heap) or <strong>Kruskal's Algorithm</strong> (Disjoint Set Union - DSU)?</p>
