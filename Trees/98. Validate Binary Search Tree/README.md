<h2>98. Validate Binary Search Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the <strong>root</strong> of a binary tree, determine if it is a valid <strong>Binary Search Tree (BST)</strong>.</p>

<p>A valid BST is defined as follows:</p>

<ul>
  <li>The left subtree of a node contains only nodes with keys <strong>less than</strong> the node's key.</li>
  <li>The right subtree of a node contains only nodes with keys <strong>greater than</strong> the node's key.</li>
  <li>Both the left and right subtrees must also be valid BSTs.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
root = [2,1,3]

<strong>Output:</strong>
true

<strong>Explanation:</strong>

    2
   / \
  1   3

All values in the left subtree are smaller than 2,
and all values in the right subtree are greater than 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
root = [5,1,4,null,null,3,6]

<strong>Output:</strong>
false

<strong>Explanation:</strong>

      5
     / \
    1   4
       / \
      3   6

Although 3 is smaller than 4, it lies in the
right subtree of 5. Therefore, it should be
greater than 5, making the tree invalid.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
  <li><code>-2<sup>31</sup> ≤ Node.val ≤ 2<sup>31</sup> - 1</code>.</li>
</ul>

<p><strong>Approach:</strong></p>

<p>A node's value cannot simply be compared only with its immediate parent. It must satisfy the constraints imposed by <strong>all of its ancestors</strong>.</p>

<p>For every node, maintain a valid range:</p>

<pre>
left &lt; node.val &lt; right
</pre>

<p>Initially, the root can contain any valid integer value, so its range is:</p>

<pre>
(-∞, +∞)
</pre>

<p>When moving to the left child, the upper bound becomes the current node's value.</p>

<pre>
left subtree:
(-∞, node.val)
</pre>

<p>When moving to the right child, the lower bound becomes the current node's value.</p>

<pre>
right subtree:
(node.val, +∞)
</pre>

<p>If a node violates its allowed range, the tree is not a valid BST.</p>

<p><strong>Alternative Approach:</strong></p>

<p>A valid BST produces a <strong>strictly increasing sequence</strong> during inorder traversal.</p>

<pre>
        2
       / \
      1   3

Inorder:
1 → 2 → 3

Since the sequence is strictly increasing,
the tree is a valid BST.
</pre>

<p><strong>Important:</strong> Duplicate values are not allowed in a valid BST for this problem.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(h)</code> for recursion, where <code>h</code> is the height of the tree.</p>
