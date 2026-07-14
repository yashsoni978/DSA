<h2>Articulation Point</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>You are given an undirected graph with <code>V</code> vertices and <code>E</code> edges. The graph is represented as a 2D array <code>edges[][]</code>, where each element <code>edges[i] = [u, v]</code> denotes an undirected edge between vertices <code>u</code> and <code>v</code>.</p>

<p>Your task is to return all the <strong>articulation points</strong> (also known as <strong>cut vertices</strong>) in the graph.</p>

<p>An <strong>articulation point</strong> is a vertex whose removal (along with all its incident edges) increases the number of connected components in the graph.</p>

<p><strong>Note:</strong> The graph may be disconnected, i.e., it can consist of multiple connected components. If no articulation point exists, return <code>{-1}</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 5
edges[][] = [[0,1],[1,4],[4,3],[4,2],[2,3]]

<strong>Output:</strong>
[1,4]

<strong>Explanation:</strong>

Removing vertex 1 disconnects vertex 0 from the rest of the graph.

Removing vertex 4 disconnects the graph into multiple components.

Hence, the articulation points are 1 and 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 4
edges[][] = [[0,1],[0,2]]

<strong>Output:</strong>
[0]

<strong>Explanation:</strong>

Removing vertex 0 increases the number of connected
components to 3.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ V, E ≤ 10<sup>4</sup></code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(V + E)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem in <code>O(V + E)</code> time using <strong>Tarjan's Algorithm</strong> by computing the discovery time and low-link values of each vertex?</p>
