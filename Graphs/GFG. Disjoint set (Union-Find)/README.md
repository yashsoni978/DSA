<h2>Disjoint Set (Union-Find)</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>You are given <code>n</code> elements numbered from <code>1</code> to <code>n</code>. Initially, each element belongs to its own group and is its own representative.</p>

<p>You need to process <code>k</code> queries of the following two types:</p>

<ul>
  <li>
    <strong>Type 1:</strong> <code>1 x z</code><br>
    Perform a <strong>UNION</strong> operation on elements <code>x</code> and <code>z</code>. Merge the group containing <code>x</code> into the group containing <code>z</code> by making the representative of <code>x</code> point to the representative of <code>z</code>.
  </li>
  <br>
  <li>
    <strong>Type 2:</strong> <code>2 x</code><br>
    Perform a <strong>FIND</strong> operation and return the representative of the group containing element <code>x</code>.
  </li>
</ul>

<p><strong>Note:</strong></p>

<ul>
  <li>The representative of a group is the root element whose parent is itself.</li>
  <li>Initially, every element is its own representative.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
n = 5
k = 4
queries = [[2,4],[2,1],[1,3,1],[2,3]]

<strong>Output:</strong>
[4,1,1]

<strong>Explanation:</strong>

2 4 → Representative of 4 is 4.

2 1 → Representative of 1 is 1.

1 3 1 → Merge the group containing 3 into the group containing 1.
Now parent[3] = 1.

2 3 → Representative of 3 is now 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
n = 6
k = 6
queries = [[1,2,3],[1,4,5],[2,2],[2,3],[1,3,5],[2,4]]

<strong>Output:</strong>
[3,3,5]

<strong>Explanation:</strong>

1 2 3 → Merge group of 2 into group of 3.

1 4 5 → Merge group of 4 into group of 5.

2 2 → Representative of 2 is 3.

2 3 → Representative of 3 is 3.

1 3 5 → Merge group of 3 into group of 5.

2 4 → Representative of 4 is 5.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ n, k ≤ 1000</code></li>
  <li><code>1 ≤ x, z ≤ n</code></li>
</ul>

<p><strong>Expected Time Complexity:</strong> <code>O(k × α(n))</code></p>

<p><strong>Expected Auxiliary Space:</strong> <code>O(n)</code></p>

<p><strong>Follow-up:</strong> Can you optimize the <strong>Union-Find</strong> data structure using <strong>Path Compression</strong> along with <strong>Union by Rank</strong> or <strong>Union by Size</strong> to achieve nearly constant-time operations?</p>
