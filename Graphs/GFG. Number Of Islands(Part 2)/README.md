<h2>Number Of Islands</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an <code>n × m</code> grid, where initially every cell contains <code>0</code> (water).</p>

<p>You are also given an array of <code>k</code> operations, where each operation <code>A[i] = [row, col]</code> changes the corresponding cell from water (<code>0</code>) to land (<code>1</code>).</p>

<p>After each operation, return the <strong>number of islands</strong> present in the grid.</p>

<p>An <strong>island</strong> is a group of adjacent land cells connected horizontally or vertically.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>

n = 4
m = 5
k = 4

A = [[1,1],[0,1],[3,3],[3,4]]

<strong>Output:</strong>

[1,1,2,2]

<strong>Explanation:</strong>

Initially:
00000
00000
00000
00000

After (1,1):
00000
01000
00000
00000

Islands = 1

After (0,1):
01000
01000
00000
00000

Islands = 1

After (3,3):
01000
01000
00000
00010

Islands = 2

After (3,4):
01000
01000
00000
00011

Islands = 2
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>

n = 4
m = 5
k = 4

A = [[0,0],[1,1],[2,2],[3,3]]

<strong>Output:</strong>

[1,2,3,4]

<strong>Explanation:</strong>

Each operation creates a new isolated island,
so the island count increases after every operation.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n, m ≤ 100</code></li>
  <li><code>1 ≤ k ≤ 1000</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(n × m)</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(n × m)</code></p>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using a <strong>Disjoint Set Union (Union-Find)</strong> data structure by dynamically merging adjacent land cells after each operation?</p>
