<h2>684. Redundant Connection</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given a graph that started as a <strong>tree</strong> with <code>n</code> nodes labeled from <code>1</code> to <code>n</code>. A single edge was added to the tree, resulting in a graph with exactly one cycle.</p>

<p>Return an edge that can be removed so that the resulting graph is a tree. If there are multiple valid answers, return the edge that occurs <strong>last</strong> in the input.</p>

<p>The edges are given as a 2D array <code>edges</code>, where <code>edges[i] = [u, v]</code> represents an undirected edge between nodes <code>u</code> and <code>v</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
edges = [[1,2],[1,3],[2,3]]

<strong>Output:</strong>
[2,3]

<strong>Explanation:</strong>
The graph contains a cycle:

1 -- 2
|    /
|   /
3 ---

Removing the edge [2,3] makes the graph a tree.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]

<strong>Output:</strong>
[1,4]

<strong>Explanation:</strong>
The edge [1,4] creates the cycle:

1 -- 2 -- 3 -- 4
|              |
└──────────────┘

Removing [1,4] makes the graph a tree.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == edges.length</code></li>
  <li><code>3 ≤ n ≤ 1000</code></li>
  <li><code>edges[i].length == 2</code></li>
  <li><code>1 ≤ u &lt; v ≤ n</code></li>
  <li><code>u != v</code></li>
  <li>There are no repeated edges.</li>
  <li>The given graph is connected.</li>
  <li>The graph contains exactly one cycle.</li>
</ul>

<p><strong>Approach:</strong></p>

<p>Process the edges one by one. Before adding an edge <code>[u, v]</code>, check whether <code>u</code> and <code>v</code> are already connected.</p>

<p>If they are already connected, adding this edge would create a cycle, so this is the redundant edge.</p>

<p>We can use <strong>Disjoint Set Union (DSU)</strong> / <strong>Union-Find</strong> to efficiently determine whether two nodes belong to the same connected component.</p>

<ul>
  <li><strong>Find:</strong> Finds the representative (root) of a node's component.</li>
  <li><strong>Union:</strong> Combines two different components.</li>
  <li>If two nodes have the same representative, adding their edge creates a cycle.</li>
</ul>

<p><strong>Time Complexity:</strong> <code>O(E × α(V))</code> ≈ <code>O(E)</code></p>

<p><strong>Space Complexity:</strong> <code>O(V)</code></p>
