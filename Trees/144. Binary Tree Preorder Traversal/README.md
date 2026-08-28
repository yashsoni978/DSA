<h2>144. Binary Tree Preorder Traversal</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given the root of a binary tree, return the <strong>preorder traversal</strong> of its nodes.</p>

<p>Preorder traversal follows:</p>

<pre>
Root → Left → Right
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Depth First Search (DFS)</strong>.</li>
<li>First visit the current node and add its value to the answer.</li>
<li>Then recursively traverse the left subtree.</li>
<li>Finally, recursively traverse the right subtree.</li>
<li>If the current node is <code>null</code>, return.</li>
</ul>

<h3>Why This Works</h3>

<p>Preorder traversal requires every node to be processed in the exact order:</p>

<pre>
1. Root
2. Left subtree
3. Right subtree
</pre>

<p>Recursion naturally follows this order.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>

<p>Every node is visited exactly once.</p>

<p><strong>Space:</strong> <code>O(h)</code></p>

<p>Where <code>h</code> is the height of the tree due to the recursion stack.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Preorder Traversal</p>

<p><strong>Key Idea:</strong> Visit <strong>Root → Left → Right</strong>. Add the current node first, then recursively process its left and right subtrees.</p>
