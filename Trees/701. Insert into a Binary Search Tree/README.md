<h2>701. Insert into a Binary Search Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
BST Property:

value &lt; root-&gt;val
        ↓
      GO LEFT

value &gt; root-&gt;val
        ↓
      GO RIGHT
</pre>

<p>To insert a new value, follow the BST property until we find a <strong>NULL position</strong>. Create the new node there.</p>

<h3>Approach</h3>

<ul>
<li>If <code>root == NULL</code>, create and return a new node.</li>
<li>If <code>val &lt; root-&gt;val</code>, insert into the left subtree.</li>
<li>If <code>val &gt; root-&gt;val</code>, insert into the right subtree.</li>
<li>Return the root after insertion.</li>
</ul>

<h3>Example</h3>

<pre>
        4
       / \
      2   7
     / \
    1   3

Insert = 5

5 &gt; 4 → RIGHT
5 &lt; 7 → LEFT
LEFT of 7 is NULL

Insert 5 there:

        4
       / \
      2   7
     / \ /
    1  3 5
</pre>

<h3>Code</h3>

<pre>
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            return new TreeNode(val);
        }

        if(val &lt; root-&gt;val) {
            root-&gt;left = insertIntoBST(root-&gt;left, val);
        }
        else {
            root-&gt;right = insertIntoBST(root-&gt;right, val);
        }

        return root;
    }
};
</pre>

<h3>Key Idea</h3>

<pre>
Start at root

val &lt; root-&gt;val
       ↓
      LEFT

val &gt; root-&gt;val
       ↓
      RIGHT

NULL found
       ↓
Create new node
</pre>

<h3>Complexity</h3>

<pre>
TC: O(h)

Balanced BST → O(log n)
Skewed BST   → O(n)

SC: O(h)

Due to recursion stack.

Balanced BST → O(log n)
Skewed BST   → O(n)
</pre>

<hr>

<p><strong>Pattern:</strong> BST / Binary Search / Recursion</p>

<p><strong>Key Idea:</strong> Follow the BST property until a NULL position is found, then insert the new node there.</p>
