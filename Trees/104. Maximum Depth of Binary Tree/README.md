<h2>104. Maximum Depth of Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given the root of a binary tree, return its <strong>maximum depth</strong>.</p>

<p>The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>Depth First Search (DFS)</strong> with recursion.</li>
<li>If the current node is <code>null</code>, return <code>0</code>.</li>
<li>Recursively find the depth of the left subtree.</li>
<li>Recursively find the depth of the right subtree.</li>
<li>The depth of the current node is <code>1 + max(leftDepth, rightDepth)</code>.</li>
</ul>

<h3>Why This Works</h3>

<p>For every node, we find the longest path through either its left or right subtree.</p>

<pre>
depth(node) = 1 + max(depth(left), depth(right))
</pre>

<p>The <code>1</code> represents the current node.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>

<p>Every node is visited exactly once.</p>

<p><strong>Space:</strong> <code>O(h)</code></p>

<p>Where <code>h</code> is the height of the tree due to the recursion stack.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Recursion</p>

<p><strong>Key Idea:</strong> Find the maximum depth of both subtrees and add <code>1</code> for the current node.</p>
