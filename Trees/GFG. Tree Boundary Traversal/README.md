<h2>Tree Boundary Traversal</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the root of a binary tree, return its <strong>boundary traversal</strong>.</p>

<p>The boundary consists of:</p>

<pre>
Left Boundary → Leaf Nodes → Reverse Right Boundary
</pre>

<h3>Approach</h3>

<ul>
<li>First add the <strong>root</strong> if it is not a leaf.</li>
<li>Traverse the <strong>left boundary</strong>, always preferring the left child, and exclude leaf nodes.</li>
<li>Traverse the tree to collect all <strong>leaf nodes</strong> from left to right.</li>
<li>Traverse the <strong>right boundary</strong>, always preferring the right child, and exclude leaf nodes.</li>
<li>Store the right boundary separately and add it in <strong>reverse order</strong>.</li>
<li>For a single-node tree, simply return the root.</li>
</ul>

<h3>Important Concept</h3>

<p>Leaf nodes are handled separately, so they should <strong>not</strong> be included again while traversing the left or right boundary.</p>

<pre>
Boundary =

Root
  ↓
Left Boundary
  ↓
All Leaves (Left → Right)
  ↓
Right Boundary (Bottom → Top)
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>

<p>Every node is visited at most a constant number of times.</p>

<p><strong>Space:</strong> <code>O(h)</code></p>

<p>Where <code>h</code> is the height of the tree due to recursion and the temporary right boundary.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Boundary Traversal</p>

<p><strong>Key Idea:</strong> Divide the traversal into <strong>left boundary → leaves → reversed right boundary</strong>, while excluding leaves from the boundary parts to avoid duplicates.</p>
