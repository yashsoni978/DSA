<h2>222. Count Complete Tree Nodes</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the root of a <strong>complete binary tree</strong>, return the total number of nodes.</p>

<h3>Optimal Approach</h3>

<p>A complete binary tree has a special property: if the height of the leftmost path and rightmost path are equal, the tree is a <strong>perfect binary tree</strong>.</p>

<ul>
<li>Find the height of the leftmost path.</li>
<li>Find the height of the rightmost path.</li>
<li>If both heights are equal:</li>
</ul>

<pre>
Number of nodes = 2^h - 1
</pre>

<ul>
<li>Otherwise, recursively count the nodes in the left and right subtrees.</li>
</ul>

<h3>Key Idea</h3>

<pre>
              root
             /    \
            /      \
        left        right

leftHeight == rightHeight
        ↓
Perfect tree
        ↓
2^h - 1

Otherwise
        ↓
1 + count(left) + count(right)
</pre>

<h3>Why This Is Better Than O(n)</h3>

<p>A normal traversal visits every node → <code>O(n)</code>.</p>

<p>Here, we only calculate the height of the left/right edges at each recursive level. Since the tree is complete, this gives:</p>

<pre>
TC: O(log² n)

SC: O(log n)

Recursion depth is the height of the tree.
</pre>

<hr>

<p><strong>Pattern:</strong> Binary Tree / Complete Binary Tree / Height / Recursion</p>

<p><strong>Key Idea:</strong> If leftmost and rightmost heights are equal, the subtree is perfect and its node count can be calculated directly using <code>2^h - 1</code>.</p>
