<h2>743. Network Delay Time</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given a network of <code>n</code> nodes, labeled from <code>1</code> to <code>n</code>. You are also given a list of directed edges <code>times</code>, where <code>times[i] = [u, v, w]</code> represents a signal traveling from node <code>u</code> to node <code>v</code> in <code>w</code> units of time.</p>

<p>A signal is sent from a given node <code>k</code>. Return the <strong>minimum time</strong> it takes for all the <code>n</code> nodes to receive the signal. If it is impossible for all nodes to receive the signal, return <code>-1</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
times = [[2,1,1],[2,3,1],[3,4,1]]
n = 4
k = 2

<strong>Output:</strong>
2

<strong>Explanation:</strong>
The signal starts from node 2.

2 → 1 takes 1 unit of time.
2 → 3 takes 1 unit of time.
2 → 3 → 4 takes 2 units of time.

Therefore, all nodes receive the signal by time 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
times = [[1,2,1]]
n = 2
k = 2

<strong>Output:</strong>
-1

<strong>Explanation:</strong>
The signal starts at node 2, but there is no path from
node 2 to node 1.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ k ≤ n ≤ 100</code></li>
  <li><code>1 ≤ times.length ≤ 6000</code></li>
  <li><code>times[i].length == 3</code></li>
  <li><code>1 ≤ u, v ≤ n</code></li>
  <li><code>u != v</code></li>
  <li><code>0 ≤ w ≤ 100</code></li>
  <li>All pairs <code>(u, v)</code> are unique.</li>
</ul>

<p><strong>Approach:</strong></p>

<p>This is a <strong>single-source shortest path</strong> problem on a directed weighted graph. Since all edge weights are non-negative, we can use <strong>Dijkstra's Algorithm</strong>.</p>

<ol>
  <li>Build a directed adjacency list from <code>times</code>.</li>
  <li>Initialize the distance of the source node <code>k</code> to <code>0</code>.</li>
  <li>Use a min-heap (priority queue) to always process the node with the smallest known distance.</li>
  <li>Relax all outgoing edges from the current node.</li>
  <li>After Dijkstra finishes, find the maximum shortest distance among all nodes.</li>
  <li>If any node is unreachable, return <code>-1</code>.</li>
</ol>

<p><strong>Important:</strong> The edges are <strong>directed</strong>. For <code>[u, v, w]</code>, only add:</p>

<pre>
adj[u].push_back({v, w});
</pre>

<p>Do not add the reverse edge.</p>

<p><strong>Why take the maximum distance?</strong></p>

<p>We need the time when <strong>all</strong> nodes have received the signal. Therefore, after finding the shortest distance from <code>k</code> to every node, the answer is the largest of those distances.</p>

<pre>
dist = [0, 1, 1, 2]

answer = max(0, 1, 1, 2) = 2
</pre>

<p><strong>Time Complexity:</strong> <code>O((V + E) log V)</code></p>

<p><strong>Space Complexity:</strong> <code>O(V + E)</code></p>
