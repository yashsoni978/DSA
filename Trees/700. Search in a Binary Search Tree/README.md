<h2>700. Search in a Binary Search Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
BST Property:

Left subtree  → values smaller than root
Right subtree → values greater than root
</pre>

<p>Therefore, at every node we can decide which side can contain the target instead of traversing the entire tree. :contentReference[oaicite:0]{index=0}</p>

<h3>Approach</h3>

<ul>
<li>Start from the root.</li>
<li>If <code>root->val == val</code>, we found the node, so return it.</li>
<li>If <code>val &lt; root->val</code>, search in the left subtree.</li>
<li>If <code>val &gt; root->val</code>, search in the right subtree.</li>
<li>If we reach <code>NULL</code>, the value does not exist.</li>
</ul>

<h3>Example</h3>

<pre>
        4
       / \
      2   7
     / \
    1   3

Search = 2

4 → 2

2 == target
↓
Return node 2 and its subtree
</pre>

<h3>Code</h3>

<pre>
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;

        if(root-&gt;val == val)
            return root;

        if(val &lt; root-&gt;val)
            return searchBST(root-&gt;left, val);

        return searchBST(root-&gt;right, val);
    }
};
</pre>

<h3>Key Idea</h3>

<pre>
target &lt; root-&gt;val
        ↓
      GO LEFT

target &gt; root-&gt;val
        ↓
      GO RIGHT

target == root-&gt;val
        ↓
       FOUND
</pre>

<p>We only follow <strong>one path</strong> from the root instead of visiting every node.</p>

<h3>Complexity</h3>

<pre>
TC: O(h)

We visit at most one path from root to leaf.

Balanced BST → O(log n)
Skewed BST   → O(n)

SC: O(h)

Recursion stack can go up to the height of the tree.
</pre>

<hr>

<p><strong>Pattern:</strong> BST / Binary Search / Recursion</p>

<p><strong>Key Idea:</strong> Use the BST property to decide left or right at every node, just like binary search.</p>
