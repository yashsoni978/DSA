<h2>235. Lowest Common Ancestor of a Binary Search Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a <strong>Binary Search Tree (BST)</strong>, find the <strong>Lowest Common Ancestor (LCA)</strong> of two given nodes <code>p</code> and <code>q</code>.</p>

<p>The <strong>Lowest Common Ancestor</strong> of two nodes <code>p</code> and <code>q</code> is the lowest node in the tree that has both <code>p</code> and <code>q</code> as descendants. A node can be considered a descendant of itself.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
root = [6,2,8,0,4,7,9,null,null,3,5]
p = 2
q = 8

<strong>Output:</strong>
6

<strong>Explanation:</strong>

        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

6 is the lowest node that has both 2 and 8
as descendants.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
root = [6,2,8,0,4,7,9,null,null,3,5]
p = 2
q = 4

<strong>Output:</strong>
2

<strong>Explanation:</strong>

2 is an ancestor of 4, so 2 is their
lowest common ancestor.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
root = [2,1]
p = 2
q = 1

<strong>Output:</strong>
2
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
  <li><code>-10<sup>9</sup> ≤ Node.val ≤ 10<sup>9</sup></code>.</li>
  <li>All <code>Node.val</code> are unique.</li>
  <li><code>p != q</code>.</li>
  <li><code>p</code> and <code>q</code> will exist in the BST.</li>
</ul>

<p><strong>Approach:</strong></p>

<p>The key is to use the <strong>BST property</strong> instead of traversing the entire tree.</p>

<p>For the current node:</p>

<ul>
  <li>If both <code>p</code> and <code>q</code> are smaller than the current node, the LCA must be in the <strong>left subtree</strong>.</li>
  <li>If both <code>p</code> and <code>q</code> are greater than the current node, the LCA must be in the <strong>right subtree</strong>.</li>
  <li>Otherwise, the current node is the point where the paths to <code>p</code> and <code>q</code> split, so it is the <strong>Lowest Common Ancestor</strong>.</li>
</ul>

<p><strong>Example:</strong></p>

<pre>
        6
       / \
      2   8
     / \ / \
    0  4 7  9

p = 2, q = 8

2 &lt; 6 and 8 &gt; 6

The two nodes lie on different sides of 6.

Therefore:

LCA = 6
</pre>

<p>We can implement this iteratively:</p>

<pre>
while(root) {
    if(p-&gt;val &lt; root-&gt;val &amp;&amp; q-&gt;val &lt; root-&gt;val)
        root = root-&gt;left;

    else if(p-&gt;val &gt; root-&gt;val &amp;&amp; q-&gt;val &gt; root-&gt;val)
        root = root-&gt;right;

    else
        return root;
}
</pre>

<p><strong>Important:</strong> This solution specifically takes advantage of the <strong>BST property</strong>. In a normal binary tree, this approach would not work.</p>

<p><strong>Time Complexity:</strong> <code>O(H)</code>, where <code>H</code> is the height of the BST.</p>

<p><strong>Space Complexity:</strong> <code>O(1)</code> using the iterative approach.</p>
