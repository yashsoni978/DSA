<h2>1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>There are <code>n</code> cities numbered from <code>0</code> to <code>n - 1</code>. You are given the array <code>edges</code>, where <code>edges[i] = [from, to, weight]</code> represents a bidirectional and weighted edge between cities <code>from</code> and <code>to</code>, and you are given the integer <code>distanceThreshold</code>.</p>

<p>Return the city with the <strong>smallest number of cities</strong> that are reachable through some path whose total distance is at most <code>distanceThreshold</code>.</p>

<p>If there are multiple such cities, return the city with the <strong>greatest index</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
n = 4
edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]]
distanceThreshold = 4

<strong>Output:</strong>
3

<strong>Explanation:</strong>

The neighboring cities at a distanceThreshold = 4 for each city are:

City 0 -> [City 1, City 2]
City 1 -> [City 0, City 2, City 3]
City 2 -> [City 0, City 1, City 3]
City 3 -> [City 1, City 2]

Cities 0 and 3 have the smallest number of reachable neighbors (2),
so return city 3 since it has the greater index.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
n = 5
edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]
distanceThreshold = 2

<strong>Output:</strong>
0

<strong>Explanation:</strong>

The neighboring cities within distanceThreshold = 2 are:

City 0 -> [City 1]
City 1 -> [City 0, City 4]
City 2 -> [City 3]
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 3]

City 0 has the smallest number of reachable neighbors.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>2 ≤ n ≤ 100</code></li>
  <li><code>1 ≤ edges.length ≤ n × (n - 1) / 2</code></li>
  <li><code>edges[i].length == 3</code></li>
  <li><code>0 ≤ from &lt; to &lt; n</code></li>
  <li><code>1 ≤ weight, distanceThreshold ≤ 10<sup>4</sup></code></li>
  <li>All pairs <code>(from, to)</code> are distinct.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using the <strong>Floyd-Warshall Algorithm</strong> to compute all-pairs shortest paths and then count the number of reachable cities for each vertex?</p>
