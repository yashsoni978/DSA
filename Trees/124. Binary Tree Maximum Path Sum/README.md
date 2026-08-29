<h2>124. Binary Tree Maximum Path Sum</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given the root of a binary tree, return the <strong>maximum path sum</strong> of any non-empty path.</p>

<p>A path can start and end at any nodes, but it must follow connected parent-child relationships.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>DFS with recursion</strong>.</li>
<li>For every node, calculate the maximum path sum that can be extended to its parent.</li>
<li>A negative subtree should not be included, so use <code>max(0, subtreeSum)</code>.</li>
<li>The maximum path passing through the current node is:</li>
</ul>

<pre>
leftGain + node->val + rightGain
</pre>

<ul>
<li>Update the global answer using this value.</li>
<li>Return only one side to the parent because a path going upward cannot use both left and right branches.</li>
</ul>

<h3>Important Concept</h3>

<p>There are two different values:</p>

<pre>
Path through current node:
leftGain + node->val + rightGain

Gain returned to parent:
node->val + max(leftGain, rightGain)
</pre>

<p>The current node can use <strong>both</strong> children when updating the answer, but it can return only <strong>one</strong> child path to its parent.</p>

<h3>Why Use <code>max(0, gain)</code>?</h3>

<p>If a subtree has a negative contribution, including it would decrease the path sum. Therefore, we simply ignore it.</p>

<pre>
gain = max(0, gain)
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>

<p>Every node is visited exactly once.</p>

<p><strong>Space:</strong> <code>O(h)</code></p>

<p>Where <code>h</code> is the height of the tree due to the recursion stack.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Recursion / Maximum Path Sum</p>

<p><strong>Key Idea:</strong> At every node, calculate the best contribution from the left and right subtrees, update the global maximum using both sides, and return the better single-side contribution to the parent.</p>
