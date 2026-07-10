<h2>Shortest Path in Unweighted Graph</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an undirected graph with <code>V</code> vertices numbered from <code>0</code> to <code>V - 1</code> and <code>E</code> edges, where <code>edges[i] = [u, v]</code> denotes an undirected edge between vertices <code>u</code> and <code>v</code>, and two vertices <code>src</code> and <code>dest</code>, find the length of the shortest path from <code>src</code> to <code>dest</code>.</p>

<p>If there is no path between <code>src</code> and <code>dest</code>, return <code>-1</code>.</p>

<p><strong>Note:</strong> All edges have a unit weight of <code>1</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 9
edges[][] = [[0,1],[0,3],[1,2],[3,4],[4,5],[2,6],[5,6],[6,7],[6,8],[7,8]]
src = 0
dest = 8

<strong>Output:</strong>
4

<strong>Explanation:</strong>
One of the shortest paths is:
0 → 1 → 2 → 6 → 8

The path contains 4 edges.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 4
edges[][] = [[0,3],[1,3]]
src = 3
dest = 2

<strong>Output:</strong>
-1

<strong>Explanation:</strong>
There is no path between vertices 3 and 2.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ V ≤ 10<sup>4</sup></code></li>
  <li><code>0 ≤ E ≤ V × (V - 1) / 2</code></li>
  <li><code>0 ≤ edges[i][0], edges[i][1] &lt; V</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(V + E)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Breadth-First Search (BFS)</strong>, which guarantees the shortest path in an unweighted graph?</p>
