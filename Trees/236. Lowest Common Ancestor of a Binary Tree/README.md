<h2>236. Lowest Common Ancestor of a Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the <strong>root</strong> of a binary tree, find the <strong>Lowest Common Ancestor (LCA)</strong> of two given nodes <code>p</code> and <code>q</code>.</p>

<p>The <strong>Lowest Common Ancestor</strong> of two nodes <code>p</code> and <code>q</code> is the lowest node in the tree that has both <code>p</code> and <code>q</code> as descendants. A node can be considered a descendant of itself.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
root = [3,5,1,6,2,0,8,null,null,7,4]
p = 5
q = 1

<strong>Output:</strong>
3

<strong>Explanation:</strong>

        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

3 is the lowest node that has both 5 and 1
as descendants.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
root = [3,5,1,6,2,0,8,null,null,7,4]
p = 5
q = 4

<strong>Output:</strong>
5

<strong>Explanation:</strong>

        3
       / \
      5   1
     / \
    6   2
       / \
      7   4

5 is an ancestor of 4, so 5 is their
lowest common ancestor.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
root = [1,2]
p = 1
q = 2

<strong>Output:</strong>
1
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is in the range <code>[2, 10<sup>5</sup>]</code>.</li>
  <li><code>-10<sup>9</sup> ≤ Node.val ≤ 10<sup>9</sup></code>.</li>
  <li>All <code>Node.val</code> are unique.</li>
  <li><code>p != q</code>.</li>
  <li><code>p</code> and <code>q</code> will exist in the binary tree.</li>
</ul>

<p><strong>Approach:</strong></p>

<p>Unlike LC 235, this problem uses a <strong>normal Binary Tree</strong>, so we cannot use the BST property to decide whether to move left or right.</p>

<p>Use <strong>Postorder DFS</strong> to search for <code>p</code> and <code>q</code> in both subtrees.</p>

<p>For every node:</p>

<ul>
  <li>If the current node is <code>null</code>, return <code>null</code>.</li>
  <li>If the current node is <code>p</code> or <code>q</code>, return the current node.</li>
  <li>Recursively search the left subtree.</li>
  <li>Recursively search the right subtree.</li>
  <li>If both left and right return a non-null node, then <strong>p and q are found in different subtrees</strong>, so the current node is their LCA.</li>
  <li>If only one side returns a non-null node, return that node upward.</li>
</ul>

<p><strong>Example:</strong></p>

<pre>
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

p = 5
q = 4
</pre>

<p>DFS reaches node <code>5</code>, which is <code>p</code>, so it returns <code>5</code>.</p>

<p>The recursive calls then propagate <code>5</code> upward. Since <code>5</code> is already an ancestor of <code>4</code>, the answer is:</p>

<pre>
LCA = 5
</pre>

<p><strong>Recursive Logic:</strong></p>

<pre>
if(root == null)
    return null;

if(root == p || root == q)
    return root;

left = LCA(root-&gt;left, p, q);
right = LCA(root-&gt;right, p, q);

if(left != null &amp;&amp; right != null)
    return root;

return left != null ? left : right;
</pre>

<p><strong>Important:</strong> This solution works for a <strong>normal Binary Tree</strong>. Unlike LC 235, there is no ordering property that tells us whether <code>p</code> or <code>q</code> is on the left or right.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(h)</code> for the recursion stack, where <code>h</code> is the height of the tree.</p>
