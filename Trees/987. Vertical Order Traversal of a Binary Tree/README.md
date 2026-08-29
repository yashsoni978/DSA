<h2>987. Vertical Order Traversal of a Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given the root of a binary tree, return its <strong>vertical order traversal</strong>.</p>

<p>For each node, assign coordinates:</p>

<pre>
Root → (row = 0, col = 0)

Left child  → (row + 1, col - 1)
Right child → (row + 1, col + 1)
</pre>

<p>Nodes are ordered by:</p>

<ol>
<li><strong>Column</strong> from left to right.</li>
<li><strong>Row</strong> from top to bottom.</li>
<li>If two nodes have the same row and column, sort them by <strong>value</strong>.</li>
</ol>

<h3>Approach</h3>

<ul>
<li>Use <strong>DFS</strong> to traverse the tree while storing each node along with its <code>row</code> and <code>column</code>.</li>
<li>Store nodes in a nested map using <code>column</code> and <code>row</code>.</li>
<li>For nodes having the same row and column, store their values together.</li>
<li>Sort the values at the same position.</li>
<li>Traverse columns from smallest to largest and rows from smallest to largest to build the answer.</li>
</ul>

<h3>Why This Works</h3>

<p>The row and column coordinates uniquely determine the vertical position of every node.</p>

<pre>
        1
       / \
      2   3
     / \   \
    4   5   6

Columns:

-2 → [4]
-1 → [2]
 0 → [1,5]
 1 → [3]
 2 → [6]
</pre>

<p>Sorting by column, then row, and finally value produces the required vertical traversal.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log n)</code></p>

<p>Nodes are stored and ordered using maps and sorting.</p>

<p><strong>Space:</strong> <code>O(n)</code></p>

<p>The map stores every node value and the recursion stack uses <code>O(h)</code> space.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Coordinates / Map / Sorting</p>

<p><strong>Key Idea:</strong> Assign every node a <code>(row, column)</code> coordinate, group nodes by column, and order them by <strong>column → row → value</strong>.</p>
