<h2>787. Cheapest Flights Within K Stops</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>There are <code>n</code> cities connected by a number of flights. You are given an array <code>flights</code> where <code>flights[i] = [from, to, price]</code> indicates that there is a flight from city <code>from</code> to city <code>to</code> with cost <code>price</code>.</p>

<p>You are also given three integers <code>src</code>, <code>dst</code>, and <code>k</code>. Return the <strong>cheapest price</strong> from <code>src</code> to <code>dst</code> with at most <code>k</code> stops. If there is no such route, return <code>-1</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
n = 4
flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0
dst = 3
k = 1

<strong>Output:</strong>
700

<strong>Explanation:</strong>
The graph is shown above.

The optimal path with at most 1 stop is:
0 → 1 → 3

Total cost = 100 + 600 = 700.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
n = 3
flights = [[0,1,100],[1,2,100],[0,2,500]]
src = 0
dst = 2
k = 1

<strong>Output:</strong>
200

<strong>Explanation:</strong>
The cheapest path is:
0 → 1 → 2

Total cost = 200.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
n = 3
flights = [[0,1,100],[1,2,100],[0,2,500]]
src = 0
dst = 2
k = 0

<strong>Output:</strong>
500

<strong>Explanation:</strong>
With no stops allowed, the only valid route is:
0 → 2

Total cost = 500.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n ≤ 100</code></li>
  <li><code>0 ≤ flights.length ≤ n × (n - 1) / 2</code></li>
  <li><code>flights[i].length == 3</code></li>
  <li><code>0 ≤ from, to &lt; n</code></li>
  <li><code>from != to</code></li>
  <li><code>1 ≤ price ≤ 10<sup>4</sup></code></li>
  <li>There will not be multiple flights between the same two cities.</li>
  <li><code>0 ≤ src, dst, k &lt; n</code></li>
  <li><code>src != dst</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using <strong>BFS</strong>, <strong>Modified Dijkstra's Algorithm</strong>, or <strong>Bellman-Ford</strong> while respecting the maximum number of stops?</p>
