<h2>257. Binary Tree Paths</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Given the root of a binary tree, return all <strong>root-to-leaf paths</strong>.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>DFS + Recursion</strong>.</li>
<li>Maintain the current path as a string.</li>
<li>Add the current node's value to the path.</li>
<li>If the node is a <strong>leaf</strong>, add the complete path to the answer.</li>
<li>Otherwise, recursively traverse the left and right subtrees.</li>
<li>Use <code>"->"</code> between consecutive nodes.</li>
</ul>

<h3>Example</h3>

<pre>
        1
       / \
      2   3
       \
        5

Paths:
1 -> 2 -> 5
1 -> 3

Output:
["1->2->5", "1->3"]
</pre>

<h3>Key Idea</h3>

<pre>
DFS
 ↓
Build current path
 ↓
If leaf → store path
 ↓
Otherwise → go left/right
</pre>

<h3>Complexity</h3>

<p><strong>TC: O(n)</strong></p>

<p>Every node is visited once. Creating/storing the paths can add output-related cost.</p>

<p><strong>SC: O(h)</strong></p>

<p>The recursion stack and current path require O(h) auxiliary space, where h is the tree height.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Recursion / Root-to-Leaf Path</p>

<p><strong>Key Idea:</strong> Perform DFS while building the current root-to-node path, and save it whenever a leaf node is reached.</p>
