<h2>Bellman-Ford</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a weighted graph with <code>V</code> vertices numbered from <code>0</code> to <code>V - 1</code> and <code>E</code> edges, represented by a 2D array <code>edges[][]</code>, where <code>edges[i] = [u, v, w]</code> represents a directed edge from vertex <code>u</code> to vertex <code>v</code> with weight <code>w</code>.</p>

<p>You are also given a source vertex <code>src</code>.</p>

<p>Your task is to compute the shortest distance from <code>src</code> to every other vertex. If a vertex is unreachable, its distance should be <code>10<sup>8</sup></code>.</p>

<p>If the graph contains a <strong>negative weight cycle</strong>, return <code>[-1]</code> since shortest paths cannot be determined reliably.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 5
edges[][] = [[1,3,2],[4,3,-1],[2,4,1],[1,2,1],[0,1,5]]
src = 0

<strong>Output:</strong>
[0,5,6,6,7]

<strong>Explanation:</strong>

Shortest Paths:
0 → 1 = 5
0 → 2 = 6 (0 → 1 → 2)
0 → 3 = 6 (0 → 1 → 2 → 4 → 3)
0 → 4 = 7 (0 → 1 → 2 → 4)
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 4
edges[][] = [[0,1,4],[1,2,-6],[2,3,5],[3,1,-2]]
src = 0

<strong>Output:</strong>
[-1]

<strong>Explanation:</strong>
The graph contains a negative weight cycle:

1 → 2 → 3 → 1

Hence, shortest paths cannot be computed.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ V ≤ 100</code></li>
  <li><code>1 ≤ E ≤ V × (V - 1)</code></li>
  <li><code>-1000 ≤ w ≤ 1000</code></li>
  <li><code>0 ≤ src &lt; V</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(V × E)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem using the <strong>Bellman-Ford Algorithm</strong> by relaxing all edges <code>V - 1</code> times and performing one additional iteration to detect a negative weight cycle?</p>
