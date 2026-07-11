<h2>Shortest Path in an Undirected Graph</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a weighted undirected graph with <code>V</code> vertices numbered from <code>1</code> to <code>V</code> and <code>E</code> edges, where <code>edges[i] = [u, v, w]</code> denotes an undirected edge between vertices <code>u</code> and <code>v</code> with weight <code>w</code>.</p>

<p>Given two vertices <code>src</code> and <code>dest</code>, find the <strong>shortest path</strong> from <code>src</code> to <code>dest</code>.</p>

<p>If multiple shortest paths exist with the same total weight, return the one whose sequence of vertices is <strong>lexicographically smallest</strong>.</p>

<p>If no path exists between <code>src</code> and <code>dest</code>, return <code>{-1}</code>.</p>

<p><strong>Note:</strong> The graph contains no negative-weight edges.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
V = 5
edges[][] = [[1,2,2],[2,5,5],[2,3,4],[1,4,1],[4,3,3],[3,5,1]]
src = 1
dest = 5

<strong>Output:</strong>
[1,4,3,5]

<strong>Explanation:</strong>
The shortest path from vertex 1 to vertex 5 is:
1 → 4 → 3 → 5

Total weight = 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
V = 6
edges[][] = [[1,2,1],[1,3,1],[2,4,1],[3,4,1],[4,6,1],[2,5,2],[5,6,1]]
src = 1
dest = 6

<strong>Output:</strong>
[1,2,4,6]

<strong>Explanation:</strong>
There are two shortest paths with total weight 3:

1 → 2 → 4 → 6
1 → 3 → 4 → 6

Since [1,2,4,6] is lexicographically smaller, it is returned.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
V = 5
edges[][] = [[1,2,4],[2,3,2],[4,5,1]]
src = 1
dest = 5

<strong>Output:</strong>
[-1]

<strong>Explanation:</strong>
There is no path from vertex 1 to vertex 5.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 ≤ V ≤ 10<sup>5</sup></code></li>
  <li><code>0 ≤ E ≤ 2 × 10<sup>5</sup></code></li>
  <li><code>1 ≤ edges[i][2] ≤ 10<sup>4</sup></code></li>
  <li><code>1 ≤ src, dest ≤ V</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O((V + E) log V)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(V + E)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using <strong>Dijkstra's Algorithm</strong> while also reconstructing the path and handling the lexicographically smallest shortest path?</p>
