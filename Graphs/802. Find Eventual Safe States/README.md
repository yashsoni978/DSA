<h2>802. Find Eventual Safe States</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>There is a directed graph of <code>n</code> nodes with each node labeled from <code>0</code> to <code>n - 1</code>. The graph is represented by a 0-indexed 2D integer array <code>graph</code>, where <code>graph[i]</code> is an integer array of nodes adjacent to node <code>i</code>, meaning there is an edge from node <code>i</code> to each node in <code>graph[i]</code>.</p>

<p>A node is a <strong>terminal node</strong> if there are no outgoing edges. A node is a <strong>safe node</strong> if every possible path starting from that node eventually ends at a terminal node (or another safe node).</p>

<p>Return an array containing all the <strong>safe nodes</strong> of the graph. The answer should be sorted in <strong>ascending order</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
graph = [[1,2],[2,3],[5],[0],[5],[],[]]

<strong>Output:</strong>
[2,4,5,6]

<strong>Explanation:</strong>
Nodes 5 and 6 are terminal nodes.
Every path starting from nodes 2 and 4 eventually reaches a terminal node.
Nodes 0, 1, and 3 are part of a cycle, so they are not safe.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]

<strong>Output:</strong>
[4]
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>n == graph.length</code></li>
  <li><code>1 &lt;= n &lt;= 10<sup>4</sup></code></li>
  <li><code>0 &lt;= graph[i].length &lt;= n</code></li>
  <li><code>0 &lt;= graph[i][j] &lt;= n - 1</code></li>
  <li><code>graph[i]</code> is sorted in strictly increasing order.</li>
  <li>The graph may contain self-loops.</li>
  <li>The number of edges in the graph will not exceed <code>4 × 10<sup>4</sup></code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>DFS</strong> (cycle detection) or <strong>Topological Sort (Kahn's Algorithm)</strong> in <code>O(V + E)</code> time?</p>
