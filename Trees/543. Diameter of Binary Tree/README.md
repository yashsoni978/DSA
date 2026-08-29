<h2>543. Diameter of Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given the root of a binary tree, return the <strong>length of the diameter</strong> of the tree.</p>

<p>The diameter is the longest path between any two nodes in the tree. The path does not necessarily have to pass through the root.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>DFS with recursion</strong> to calculate the height of every subtree.</li>
<li>For each node, calculate the height of its left and right subtrees.</li>
<li>The longest path passing through the current node is:</li>
</ul>

<pre>
leftHeight + rightHeight
</pre>

<ul>
<li>Keep a global <code>diameter</code> and update it for every node.</li>
<li>Return the height of the current node:</li>
</ul>

<pre>
1 + max(leftHeight, rightHeight)
</pre>

<h3>Important Concept</h3>

<p>The diameter may pass through <strong>any node</strong>, not necessarily the root.</p>

<pre>
Diameter through current node
        =
left subtree height + right subtree height
</pre>

<p>We calculate the height and diameter together in a single DFS traversal.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>

<p>Every node is visited exactly once.</p>

<p><strong>Space:</strong> <code>O(h)</code></p>

<p>Where <code>h</code> is the height of the tree due to the recursion stack.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Recursion / Height of Tree</p>

<p><strong>Key Idea:</strong> For every node, calculate <code>leftHeight + rightHeight</code> and keep the maximum as the diameter, while returning the node's height to its parent.</p>
