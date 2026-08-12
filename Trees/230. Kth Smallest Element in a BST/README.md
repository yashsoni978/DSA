<h2>230. Kth Smallest Element in a BST</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the <strong>root</strong> of a Binary Search Tree and an integer <code>k</code>, return the <strong>kth smallest value</strong> among all the nodes in the tree.</p>

<p>A BST has the property that an <strong>inorder traversal</strong> visits its nodes in sorted order.</p>

<p>Therefore, the kth visited node during inorder traversal is the <strong>kth smallest element</strong>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
root = [3,1,4,null,2]
k = 1

<strong>Output:</strong>
1

<strong>Explanation:</strong>

      3
     / \
    1   4
     \
      2

Inorder traversal:

1 → 2 → 3 → 4

The 1st smallest element is 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
root = [5,3,6,2,4,null,null,1]
k = 3

<strong>Output:</strong>
3

<strong>Explanation:</strong>

        5
       / \
      3   6
     / \
    2   4
   /
  1

Inorder traversal:

1 → 2 → 3 → 4 → 5 → 6

The 3rd smallest element is 3.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li>The number of nodes in the tree is <code>n</code>.</li>
  <li><code>1 ≤ k ≤ n ≤ 10<sup>4</sup></code>.</li>
  <li><code>0 ≤ Node.val ≤ 10<sup>4</sup></code>.</li>
</ul>

<p><strong>Approach:</strong></p>

<p>Since the given tree is a <strong>Binary Search Tree</strong>, its inorder traversal produces values in <strong>ascending order</strong>.</p>

<p>Instead of storing the entire inorder traversal, keep a counter while performing inorder traversal.</p>

<ol>
  <li>Traverse the left subtree.</li>
  <li>Visit the current node and increment the counter.</li>
  <li>If the counter becomes equal to <code>k</code>, the current node is the answer.</li>
  <li>Otherwise, traverse the right subtree.</li>
</ol>

<p><strong>Example:</strong></p>

<pre>
        3
       / \
      1   4
       \
        2

Inorder traversal:

1 → 2 → 3 → 4
↑
1st smallest
</pre>

<p>For <code>k = 3</code>, the traversal visits:</p>

<pre>
1 → count = 1
2 → count = 2
3 → count = 3  ← answer
</pre>

<p><strong>Optimized Approach:</strong></p>

<p>We can stop the traversal immediately once the kth node is found instead of traversing the entire tree.</p>

<p><strong>Time Complexity:</strong> <code>O(H + k)</code> in the optimized traversal, where <code>H</code> is the height of the tree.</p>

<p><strong>Space Complexity:</strong> <code>O(H)</code> for the recursion stack.</p>
