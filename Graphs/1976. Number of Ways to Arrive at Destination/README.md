<h2>1976. Number of Ways to Arrive at Destination</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are in a city that consists of <code>n</code> intersections numbered from <code>0</code> to <code>n - 1</code> with bi-directional roads between some intersections.</p>

<p>The input is generated such that you can reach any intersection from any other intersection, and there is at most one road between any two intersections.</p>

<p>You are given an integer <code>n</code> and a 2D integer array <code>roads</code>, where <code>roads[i] = [u, v, time]</code> means that there is a road between intersections <code>u</code> and <code>v</code> that takes <code>time</code> minutes to travel.</p>

<p>Return the <strong>number of different shortest paths</strong> from intersection <code>0</code> to intersection <code>n - 1</code>. Since the answer may be large, return it modulo <code>10<sup>9</sup> + 7</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
n = 7
roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],
         [3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]

<strong>Output:</strong>
4

<strong>Explanation:</strong>
The shortest travel time from 0 to 6 is 7 minutes.

There are four different shortest paths:
0 → 6
0 → 4 → 6
0 → 1 → 2 → 5 → 6
0 → 1 → 3 → 5 → 6
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
n = 2
roads = [[1,0,10]]

<strong>Output:</strong>
1

<strong>Explanation:</strong>
There is only one path from intersection 0 to 1.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n ≤ 200</code></li>
  <li><code>n - 1 ≤ roads.length ≤ n × (n - 1) / 2</code></li>
  <li><code>roads[i].length == 3</code></li>
  <li><code>0 ≤ u, v &lt; n</code></li>
  <li><code>u != v</code></li>
  <li><code>1 ≤ time ≤ 10<sup>9</sup></code></li>
  <li>There is at most one road connecting any two intersections.</li>
  <li>You can reach any intersection from any other intersection.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dijkstra's Algorithm</strong> while maintaining both the shortest distance and the number of shortest paths to each node?</p>
