<h2>94. Binary Tree Inorder Traversal</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given the root of a binary tree, return the <strong>inorder traversal</strong> of its nodes.</p>

<p>Inorder traversal follows:</p>

<pre>
Left → Root → Right
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Depth First Search (DFS)</strong>.</li>
<li>First recursively traverse the left subtree.</li>
<li>Then visit and store the current node.</li>
<li>Finally, recursively traverse the right subtree.</li>
<li>If the current node is <code>null</code>, return.</li>
</ul>

<h3>Why This Works</h3>

<p>Inorder traversal always processes nodes in the following order:</p>

<pre>
1. Left subtree
2. Root
3. Right subtree
</pre>

<p>Recursion naturally follows this order. :contentReference[oaicite:0]{index=0}</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>

<p>Every node is visited exactly once.</p>

<p><strong>Space:</strong> <code>O(h)</code></p>

<p>Where <code>h</code> is the height of the tree due to the recursion stack.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Inorder Traversal</p>

<p><strong>Key Idea:</strong> Visit <strong>Left → Root → Right</strong>. Recursively process the left subtree, add the current node, and then process the right subtree.</p>
