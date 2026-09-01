<h2>Largest BST</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<p>We need to find the <strong>largest subtree</strong> of a binary tree that itself satisfies the BST property.</p>

<p>For every node, we need to know information about its left and right subtrees:</p>

<pre>
1. Is the left subtree a BST?
2. Is the right subtree a BST?
3. What is the minimum value in the subtree?
4. What is the maximum value in the subtree?
5. What is the size of the subtree?
</pre>

<p>This information can be calculated using <strong>postorder traversal</strong>.</p>

<pre>
Left → Right → Root
</pre>

<p>We process the children first, then use their information to determine whether the current node forms a BST.</p>

<h3>BST Condition</h3>

<p>For a node to form a BST with its left and right subtrees:</p>

<pre>
left subtree is BST
AND
right subtree is BST
AND
left maximum &lt; current node
AND
current node &lt; right minimum
</pre>

<p>If all conditions are satisfied, the entire subtree rooted at the current node is a BST.</p>

<h3>Information Returned by Each Node</h3>

<pre>
For every subtree return:

minimum value
maximum value
size
isBST
</pre>

<p>Think of it as sending a small information packet from the children to their parent.</p>

<h3>Example</h3>

<pre>
        5
       / \
      2   4
     / \
    1   3
</pre>

<p>Left subtree:</p>

<pre>
    2
   / \
  1   3

min = 1
max = 3
size = 3
isBST = true
</pre>

<p>Right subtree:</p>

<pre>
4

min = 4
max = 4
size = 1
isBST = true
</pre>

<p>Now check node <code>5</code>:</p>

<pre>
left max = 3
root     = 5
right min = 4

3 &lt; 5
but right subtree must contain values &gt; 5

4 &lt; 5
       ↑
    violation
</pre>

<p>Therefore, the subtree rooted at <code>5</code> is <strong>not a BST</strong>.</p>

<p>But the subtree rooted at <code>2</code> is a valid BST of size <strong>3</strong>.</p>

<h3>Important Trick for an Invalid Subtree</h3>

<p>If the current subtree is not a BST, we should make sure its information cannot accidentally make its parent appear to be a valid BST.</p>

<pre>
If current subtree is NOT BST:

isBST = false
size  = size of largest BST found so far
</pre>

<p>Conceptually, we pass boundary values that make the parent fail the BST condition.</p>

<h3>Approach</h3>

<ul>
<li>Perform a postorder traversal.</li>
<li>Get information from the left subtree.</li>
<li>Get information from the right subtree.</li>
<li>Check whether the current node satisfies the BST conditions.</li>
<li>If it is a BST, calculate its size.</li>
<li>Update the maximum BST size.</li>
<li>If it is not a BST, continue searching its children for the largest BST.</li>
</ul>

<h3>Key Idea</h3>

<pre>
Postorder:

        Root
       /    \
    Left    Right
      ↓       ↓
  Get info  Get info
      \       /
       \     /
        Root
          ↓
   Check BST condition
          ↓
   Calculate subtree size
          ↓
   Update maximum answer
</pre>

<h3>Why Postorder?</h3>

<p>We cannot determine whether a subtree is a BST until we know whether its children are BSTs and what their minimum/maximum values are.</p>

<pre>
Children information
        ↓
Current node
        ↓
Current subtree information
</pre>

<p>That is exactly what <strong>postorder traversal</strong> provides.</p>

<h3>Complexity</h3>

<pre>
TC: O(n)

Every node is processed exactly once.

SC: O(h)

Recursion stack depends on tree height.

Balanced tree → O(log n)
Skewed tree   → O(n)
</pre>

<hr>

<p><strong>Pattern:</strong> Binary Tree / Postorder / Subtree Information / BST Validation / DP on Trees</p>

<p><strong>Key Idea:</strong> Process the tree bottom-up. For every node, combine the minimum, maximum, size, and BST status of its left and right subtrees to determine whether the current subtree is a BST.</p>
