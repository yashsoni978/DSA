<h2>947. Most Stones Removed with Same Row or Column</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>On a 2D plane, we place <code>n</code> stones at some integer coordinate points. Each coordinate point may have at most one stone.</p>

<p>A stone can be removed if it shares either the <strong>same row</strong> or the <strong>same column</strong> with another stone that has not been removed.</p>

<p>Given an array <code>stones</code>, where <code>stones[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents the coordinates of the <code>i<sup>th</sup></code> stone, return the <strong>maximum number of stones</strong> that can be removed.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]

<strong>Output:</strong>
5

<strong>Explanation:</strong>
One possible order of removals is:
1. Remove stone [2,2] because it shares a row with [2,1].
2. Remove stone [2,1] because it shares a column with [0,1].
3. Remove stone [1,2] because it shares a column with [2,2].
4. Remove stone [1,0] because it shares a row with [1,2].
5. Remove stone [0,1] because it shares a row with [0,0].

Only one stone remains.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]

<strong>Output:</strong>
3

<strong>Explanation:</strong>
One possible sequence removes 3 stones, leaving 2 stones.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
stones = [[0,0]]

<strong>Output:</strong>
0

<strong>Explanation:</strong>
A single stone cannot be removed.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ stones.length ≤ 1000</code></li>
  <li><code>0 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>4</sup></code></li>
  <li>No two stones are at the same coordinate.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using a <strong>Disjoint Set Union (Union-Find)</strong> by treating rows and columns as connected components, or using <strong>DFS</strong> to count connected components?</p>
