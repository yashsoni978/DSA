<h2>110. Balanced Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given the root of a binary tree, determine whether the tree is <strong>height-balanced</strong>.</p>

<p>A binary tree is balanced if, for every node, the difference between the heights of its left and right subtrees is at most <code>1</code>.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>DFS with recursion</strong>.</li>
<li>For each node, calculate the height of its left and right subtrees.</li>
<li>If the height difference is greater than <code>1</code>, the tree is not balanced.</li>
<li>Return <code>-1</code> immediately when an unbalanced subtree is found.</li>
<li>Otherwise, return the height of the current subtree.</li>
</ul>

<h3>Why This Works</h3>

<p>Instead of calculating the height separately for every node, we calculate the height and check balance <strong>at the same time</strong>.</p>

<pre>
If subtree is unbalanced → return -1

Otherwise:
height = 1 + max(leftHeight, rightHeight)
</pre>

<p>This avoids repeatedly traversing the same subtrees.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>

<p>Every node is visited once.</p>

<p><strong>Space:</strong> <code>O(h)</code></p>

<p>Where <code>h</code> is the height of the tree due to the recursion stack.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Recursion / Height of Tree</p>

<p><strong>Key Idea:</strong> Return the subtree height while simultaneously checking whether the height difference between the left and right subtrees is at most <code>1</code>.</p>
