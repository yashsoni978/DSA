<h2>Top View of Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>The <strong>top view</strong> contains the first node visible at every horizontal distance when the binary tree is viewed from above.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>BFS (Level Order Traversal)</strong> with a queue.</li>
<li>Store each node along with its <strong>horizontal distance (HD)</strong>.</li>
<li>For the root, <code>HD = 0</code>.</li>
<li>For the left child, <code>HD = HD - 1</code>.</li>
<li>For the right child, <code>HD = HD + 1</code>.</li>
<li>Use a <code>map</code> to store the first node encountered at each horizontal distance.</li>
<li>Because BFS visits nodes level by level, the first node encountered at an HD is the topmost node.</li>
<li>Finally, traverse the map from left to right to get the answer.</li>
</ul>

<h3>Example</h3>

<pre>
        1
       / \
      2   3
       \
        4
         \
          5

HD:
2 → -1
1 →  0
3 → +1
4 →  0
5 → +1

Top View:
[2, 1, 3]
</pre>

<h3>Key Idea</h3>

<pre>
BFS + Horizontal Distance + Map

First node at each HD = Top View
</pre>

<h3>Complexity</h3>

<p><strong>TC: O(n log n)</strong></p>

<p>Each node is processed once and inserted into the ordered map.</p>

<p><strong>SC: O(n)</strong></p>

<p>The queue and map can store up to O(n) nodes.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / BFS / Horizontal Distance / Map</p>
