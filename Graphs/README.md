<h2>1192. Critical Connections in a Network</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>There are <code>n</code> servers numbered from <code>0</code> to <code>n - 1</code> connected by undirected server-to-server connections forming a network.</p>

<p>You are given an integer <code>n</code> and a list of connections, where <code>connections[i] = [a, b]</code> represents a bidirectional connection between servers <code>a</code> and <code>b</code>.</p>

<p>A <strong>critical connection</strong> is a connection that, if removed, makes some servers unable to reach some other server.</p>

<p>Return <em>all critical connections</em> in the network in any order.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
n = 4
connections = [[0,1],[1,2],[2,0],[1,3]]

<strong>Output:</strong>
[[1,3]]

<strong>Explanation:</strong>
Removing the edge 1 → 3 disconnects node 3 from the rest of the network.
Hence, it is the only critical connection.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
n = 2
connections = [[0,1]]

<strong>Output:</strong>
[[0,1]]

<strong>Explanation:</strong>
Removing the only edge disconnects the graph.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 ≤ n ≤ 10<sup>5</sup></code></li>
  <li><code>n - 1 ≤ connections.length ≤ 10<sup>5</sup></code></li>
  <li><code>0 ≤ a, b &lt; n</code></li>
  <li><code>a != b</code></li>
  <li>There are no repeated connections.</li>
  <li>The graph is connected.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem in <code>O(V + E)</code> time using <strong>Tarjan's Algorithm</strong> by computing the discovery time and low-link value of each vertex to identify all bridges?</p>
