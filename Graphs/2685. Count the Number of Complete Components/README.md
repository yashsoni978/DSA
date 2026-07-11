<h2>2685. Count the Number of Complete Components</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an integer <code>n</code>, representing the number of vertices in an undirected graph. The vertices are numbered from <code>0</code> to <code>n - 1</code>.</p>

<p>You are also given a 2D integer array <code>edges</code>, where <code>edges[i] = [u, v]</code> indicates that there is an undirected edge between vertices <code>u</code> and <code>v</code>.</p>

<p>Return the <strong>number of complete connected components</strong> of the graph.</p>

<p>A connected component is considered <strong>complete</strong> if every pair of distinct vertices in the component is directly connected by an edge.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
n = 6
edges = [[0,1],[0,2],[1,2],[3,4]]

<strong>Output:</strong>
3

<strong>Explanation:</strong>
There are three connected components:
- {0,1,2} is complete.
- {3,4} is complete.
- {5} is also considered complete.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
n = 6
edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]

<strong>Output:</strong>
1

<strong>Explanation:</strong>
Only the component {0,1,2} is complete.
The component {3,4,5} is not complete because vertices 4 and 5 are not directly connected.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= n &lt;= 50</code></li>
  <li><code>0 &lt;= edges.length &lt;= n * (n - 1) / 2</code></li>
  <li><code>edges[i].length == 2</code></li>
  <li><code>0 &lt;= u, v &lt; n</code></li>
  <li><code>u != v</code></li>
  <li>There are no repeated edges.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>DFS</strong> or <strong>BFS</strong> to identify each connected component and verify whether it forms a complete graph?</p>
