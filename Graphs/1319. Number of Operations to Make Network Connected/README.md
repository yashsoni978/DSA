<h2>1319. Number of Operations to Make Network Connected</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>There are <code>n</code> computers numbered from <code>0</code> to <code>n - 1</code> connected by Ethernet cables. Connections are represented by <code>connections</code>, where <code>connections[i] = [a, b]</code> represents a connection between computers <code>a</code> and <code>b</code>.</p>

<p>Any computer can reach any other computer directly or indirectly through the network.</p>

<p>You may remove any cable between two directly connected computers and reconnect it between any pair of disconnected computers.</p>

<p>Return the <strong>minimum number of operations</strong> needed to connect all the computers into a single network. If it is impossible, return <code>-1</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
n = 4
connections = [[0,1],[0,2],[1,2]]

<strong>Output:</strong>
1

<strong>Explanation:</strong>
Remove the cable between computers 1 and 2 and connect it between
computers 1 and 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
n = 6
connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]

<strong>Output:</strong>
2
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
n = 6
connections = [[0,1],[0,2],[0,3],[1,2]]

<strong>Output:</strong>
-1

<strong>Explanation:</strong>
There are not enough cables to connect all the computers.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n ≤ 10<sup>5</sup></code></li>
  <li><code>1 ≤ connections.length ≤ min(n × (n - 1) / 2, 10<sup>5</sup>)</code></li>
  <li><code>connections[i].length == 2</code></li>
  <li><code>0 ≤ a, b &lt; n</code></li>
  <li><code>a != b</code></li>
  <li>There are no repeated connections.</li>
  <li>No two computers are connected by more than one cable.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using a <strong>Disjoint Set Union (Union-Find)</strong> or <strong>DFS/BFS</strong> to count the number of connected components?</p>
