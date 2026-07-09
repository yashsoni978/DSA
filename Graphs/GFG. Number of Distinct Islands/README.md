<h2>785. Is Graph Bipartite?</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>There is an undirected graph with <code>n</code> nodes, where each node is numbered between <code>0</code> and <code>n - 1</code>. You are given a 2D array <code>graph</code>, where <code>graph[u]</code> is an array of nodes that node <code>u</code> is adjacent to.</p>

<p>More formally, for each <code>v</code> in <code>graph[u]</code>, there is an undirected edge between node <code>u</code> and node <code>v</code>. The graph has the following properties:</p>

<ul>
  <li>There are no self-edges (<code>graph[u]</code> does not contain <code>u</code>).</li>
  <li>There are no parallel edges (<code>graph[u]</code> does not contain duplicate values).</li>
  <li>If <code>v</code> is in <code>graph[u]</code>, then <code>u</code> is in <code>graph[v]</code>.</li>
  <li>The graph may not be connected, meaning it can have multiple connected components.</li>
</ul>

<p>Return <code>true</code> if and only if the graph is <strong>bipartite</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
graph = [[1,2,3],[0,2],[0,1,3],[0,2]]

<strong>Output:</strong>
false

<strong>Explanation:</strong>
There is no way to divide the nodes into two independent sets because the graph contains an odd-length cycle.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
graph = [[1,3],[0,2],[1,3],[0,2]]

<strong>Output:</strong>
true

<strong>Explanation:</strong>
The graph can be divided into two sets: {0,2} and {1,3}.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>graph.length == n</code></li>
  <li><code>1 &lt;= n &lt;= 100</code></li>
  <li><code>0 &lt;= graph[u].length &lt; n</code></li>
  <li><code>0 &lt;= graph[u][i] &lt; n</code></li>
  <li><code>graph[u]</code> does not contain <code>u</code>.</li>
  <li>All the values of <code>graph[u]</code> are unique.</li>
  <li>If <code>graph[u]</code> contains <code>v</code>, then <code>graph[v]</code> contains <code>u</code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you determine whether the graph is bipartite using <strong>BFS</strong> or <strong>DFS</strong> by coloring the vertices with two different colors?</p>
