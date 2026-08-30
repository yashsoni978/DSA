<h2>114. Flatten Binary Tree to Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Preorder Traversal:

Root → Left → Right

Flattened tree must follow the same order.

Every node:
    left = NULL
    right = next node in preorder
</pre>

<p>The idea is to move the <strong>left subtree between the current node and its original right subtree</strong>. :contentReference[oaicite:0]{index=0}</p>

<h3>Approach</h3>

<ul>
<li>Start from the root.</li>
<li>If the current node has a left subtree, find the <strong>rightmost node of the left subtree</strong>.</li>
<li>Connect this rightmost node to the current node's original right subtree.</li>
<li>Move the left subtree to the right side.</li>
<li>Set the current node's left pointer to <code>NULL</code>.</li>
<li>Move to <code>root->right</code> and repeat.</li>
</ul>

<h3>Example</h3>

<pre>
        1
       / \
      2   5
     / \   \
    3   4   6

At node 1:

Rightmost node of left subtree = 4

Before:
1 → right = 5

After:
4 → right = 5
1 → right = 2
1 → left  = NULL

Result:

1 → 2 → 3 → 4 → 5 → 6
</pre>

<h3>Why Rightmost Node?</h3>

<pre>
Preorder:

1 → [LEFT SUBTREE] → [RIGHT SUBTREE]

So the last node of the left subtree
must point to the original right subtree.

        1
       / \
    LEFT  RIGHT
      ↓
   last node
      |
      ↓
    RIGHT
</pre>

<h3>Code</h3>

<pre>
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root) {
            if(root-&gt;left) {
                TreeNode* curr = root-&gt;left;

                while(curr-&gt;right)
                    curr = curr-&gt;right;

                curr-&gt;right = root-&gt;right;
                root-&gt;right = root-&gt;left;
                root-&gt;left = NULL;
            }

            root = root-&gt;right;
        }
    }
};
</pre>

<h3>Key Idea</h3>

<pre>
If left exists:

rightmost(left subtree) → original right subtree

root.right = root.left
root.left = NULL

Then move to root.right.

This produces:

Root → Left Subtree → Right Subtree

which is exactly preorder.
</pre>

<h3>Complexity</h3>

<pre>
TC: O(n)

Every node is processed and the tree is modified in-place.

SC: O(1)

No extra stack, array, or data structure is used.
</pre>

<hr>

<p><strong>Pattern:</strong> Binary Tree / Preorder / In-place Tree Modification / Linked List</p>

<p><strong>Key Idea:</strong> Move the left subtree to the right and connect its rightmost node to the original right subtree.</p>
