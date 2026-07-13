<h2>Floyd Warshall</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given a weighted directed graph represented by an adjacency matrix <code>dist[][]</code> of size <code>n × n</code>, where <code>dist[i][j]</code> represents the weight of the edge from node <code>i</code> to node <code>j</code>.</p>

<p>If there is no direct edge between two nodes, <code>dist[i][j]</code> is set to <code>10<sup>8</sup></code>, representing infinity.</p>

<p>The graph may contain negative edge weights but does <strong>not</strong> contain any negative weight cycles.</p>

<p>Your task is to compute the <strong>shortest distance between every pair of vertices</strong> and modify the given matrix <code>dist[][]</code> in-place.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>

dist[][] = [
  [0,4,100000000,5,100000000],
  [100000000,0,1,100000000,6],
  [2,100000000,0,3,100000000],
  [100000000,100000000,1,0,2],
  [1,100000000,100000000,4,0]
]

<strong>Output:</strong>

[
  [0,4,5,5,7],
  [3,0,1,4,6],
  [2,6,0,3,5],
  [3,7,1,0,2],
  [1,5,5,4,0]
]

<strong>Explanation:</strong>
Each cell <code>dist[i][j]</code> stores the shortest distance
from node <code>i</code> to node <code>j</code> after considering
all possible intermediate vertices.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>

dist[][] = [
  [0,-1,2],
  [1,0,100000000],
  [3,1,0]
]

<strong>Output:</strong>

[
  [0,-1,2],
  [1,0,3],
  [2,1,0]
]

<strong>Explanation:</strong>

Shortest path from 2 → 0:
2 → 1 → 0 = 2

Shortest path from 1 → 2:
1 → 0 → 2 = 3
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ dist.size() ≤ 100</code></li>
  <li><code>-1000 ≤ dist[i][j] ≤ 1000</code></li>
  <li><code>dist[i][j]</code> can be <code>10<sup>8</sup></code> to represent infinity.</li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n³)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(1)</code> <em>(excluding the input matrix)</em></p>

<p><strong>Follow-up:</strong> Can you solve this problem using the <strong>Floyd-Warshall Algorithm</strong> by considering each vertex as an intermediate node to compute the shortest paths between all pairs of vertices?</p>
