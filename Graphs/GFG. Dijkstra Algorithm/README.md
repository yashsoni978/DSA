<h2>Dijkstra Algorithm</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an undirected, weighted graph with <code>V</code> vertices numbered from <code>0</code> to <code>V - 1</code> and <code>E</code> edges, represented by a 2D array <code>edges[][]</code>, where <code>edges[i] = [u, v, w]</code> represents an edge between vertices <code>u</code> and <code>v</code> having weight <code>w</code>.</p>

<p>Your task is to find the shortest distance from the source vertex <code>src</code> to every other vertex in the graph and return an array where the <code>i<sup>th</sup></code> element denotes the shortest distance from <code>src</code> to vertex <code>i</code>.</p>

<p><strong>Note:</strong></p>

<ul>
  <li>The graph is connected.</li>
  <li>The graph does not contain any negative weight edges.</li>
  <li>It is guaranteed that all shortest distances fit in a 32-bit integer.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 3
edges[][] = [[0,1,1],[1,2,3],[0,2,6]]
src = 2

<strong>Output:</strong>
[4,3,0]

<strong>Explanation:</strong>

Shortest Paths:
2 → 0 = 4 (2 → 1 → 0)
2 → 1 = 3 (2 → 1)
2 → 2 = 0
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 5
edges[][] = [[0,1,4],[0,2,8],[1,4,6],[2,3,2],[3,4,10]]
src = 0

<strong>Output:</strong>
[0,4,8,10,10]

<strong>Explanation:</strong>

Shortest Paths:
0 → 1 = 4
0 → 2 = 8
0 → 3 = 10 (0 → 2 → 3)
0 → 4 = 10 (0 → 1 → 4)
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ V ≤ 10<sup>6</sup></code></li>
  <li><code>1 ≤ E ≤ 10<sup>6</sup></code></li>
  <li><code>0 ≤ edges[i][0], edges[i][1] &lt; V</code></li>
  <li><code>0 ≤ edges[i][2] ≤ 10<sup>4</sup></code></li>
  <li><code>0 ≤ src &lt; V</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O((V + E) log V)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V + E)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using <strong>Dijkstra's Algorithm</strong> with a <strong>Min Priority Queue (Min Heap)</strong>?</p>
