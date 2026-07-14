<h2>Count Strongly Connected Components</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a <strong>Directed Graph</strong> with <code>V</code> vertices (numbered from <code>0</code> to <code>V - 1</code>) and <code>E</code> edges, represented as a 2D vector <code>edges[][]</code>, where each entry <code>edges[i] = [u, v]</code> denotes a directed edge from vertex <code>u</code> to vertex <code>v</code>.</p>

<p>Your task is to find the <strong>number of Strongly Connected Components (SCCs)</strong> in the graph.</p>

<p>A <strong>Strongly Connected Component (SCC)</strong> is a maximal group of vertices such that every vertex is reachable from every other vertex in the group.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 5
E = 5
edges[][] = [[0,2],[0,3],[1,0],[2,1],[3,4]]

<strong>Output:</strong>
3

<strong>Explanation:</strong>
The graph contains the following SCCs:

{0,1,2}
{3}
{4}

Hence, the answer is 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 3
E = 3
edges[][] = [[0,1],[1,2],[2,0]]

<strong>Output:</strong>
1

<strong>Explanation:</strong>
Every vertex is reachable from every other vertex,
so the entire graph forms one Strongly Connected Component.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
V = 2
E = 1
edges[][] = [[0,1]]

<strong>Output:</strong>
2

<strong>Explanation:</strong>
Neither vertex can reach the other in both directions,
so each vertex forms its own SCC.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ V ≤ 10<sup>6</sup></code></li>
  <li><code>0 ≤ E ≤ 10<sup>6</sup></code></li>
  <li><code>0 ≤ edges[i][0], edges[i][1] &lt; V</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(V + E)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V + E)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using <strong>Kosaraju's Algorithm</strong> or <strong>Tarjan's Algorithm</strong> to identify all Strongly Connected Components?</p>
