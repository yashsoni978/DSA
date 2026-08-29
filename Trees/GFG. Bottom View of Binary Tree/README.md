<h2>Bottom View of Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>The <strong>bottom view</strong> contains the last/lowest node visible at every horizontal distance when the binary tree is viewed from below.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>BFS (Level Order Traversal)</strong> with a queue.</li>
<li>Store each node along with its <strong>horizontal distance (HD)</strong>.</li>
<li>Root has <code>HD = 0</code>.</li>
<li>Left child has <code>HD - 1</code>.</li>
<li>Right child has <code>HD + 1</code>.</li>
<li>Use a <code>map</code> to store the node value for each HD.</li>
<li>Unlike Top View, <strong>overwrite the value every time</strong> we encounter the same HD.</li>
<li>Since BFS processes nodes level by level, the later node represents the bottom-most node. If nodes are at the same level and HD, the later one in BFS wins.</li>
<li>Finally, traverse the map from left to right.</li>
</ul>

<h3>Key Difference from Top View</h3>

<pre>
Top View:
First node at each HD → keep it

Bottom View:
Last node at each HD → overwrite it
</pre>

<h3>Example</h3>

<pre>
        1
       / \
      2   3
     / \   \
    4   5   6

HD:
4 → -2
2 → -1
1 →  0
5 →  0
3 → +1
6 → +2

Bottom View:
[4, 2, 5, 3, 6]
</pre>

<h3>Complexity</h3>

<p><strong>TC: O(n log n)</strong></p>

<p>Every node is processed once and inserted/updated in the ordered map.</p>

<p><strong>SC: O(n)</strong></p>

<p>The queue and map can store up to O(n) nodes.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / BFS / Horizontal Distance / Map</p>

<p><strong>Key Idea:</strong> Assign every node a horizontal distance and continuously overwrite the value at that distance. The final value at each HD forms the bottom view.</p>
