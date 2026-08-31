<h2>450. Delete Node in a BST</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<p>Deletion in a BST has <strong>3 cases</strong>:</p>

<pre>
1. Node is a LEAF
   → Simply delete it.

2. Node has ONE CHILD
   → Replace the node with its child.

3. Node has TWO CHILDREN
   → Replace it with its inorder successor
      (smallest value in the right subtree).
</pre>

<h3>Approach</h3>

<ul>
<li>Use the BST property to find the node.</li>
<li>If <code>key &lt; root-&gt;val</code>, delete from the left subtree.</li>
<li>If <code>key &gt; root-&gt;val</code>, delete from the right subtree.</li>
<li>When the node is found, handle the three deletion cases.</li>
<li>For two children, find the smallest node in the right subtree.</li>
<li>Copy its value into the current node.</li>
<li>Delete that successor node from the right subtree.</li>
</ul>

<h3>Important Case — Two Children</h3>

<pre>
        5
       / \
      3   7
         / \
        6   8

Delete 7

Inorder successor of 7 = 8? 
No — the smallest value in the RIGHT subtree is 8.

Replace 7 with 8:

        5
       / \
      3   8
         /
        6
</pre>

<p>More generally, the inorder successor is the <strong>leftmost node of the right subtree</strong>.</p>

<h3>Code</h3>

<pre>
class Solution {
private:
    TreeNode* findMin(TreeNode* root) {
        while(root-&gt;left) {
            root = root-&gt;left;
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;

        // Search for the node
        if(key &lt; root-&gt;val) {
            root-&gt;left = deleteNode(root-&gt;left, key);
        }
        else if(key &gt; root-&gt;val) {
            root-&gt;right = deleteNode(root-&gt;right, key);
        }
        else {
            // Case 1: No child
            if(!root-&gt;left &amp;&amp; !root-&gt;right) {
                delete root;
                return NULL;
            }

            // Case 2: Only right child
            if(!root-&gt;left) {
                TreeNode* temp = root-&gt;right;
                delete root;
                return temp;
            }

            // Case 2: Only left child
            if(!root-&gt;right) {
                TreeNode* temp = root-&gt;left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            TreeNode* successor = findMin(root-&gt;right);

            root-&gt;val = successor-&gt;val;

            root-&gt;right = deleteNode(root-&gt;right,
                                     successor-&gt;val);
        }

        return root;
    }
};
</pre>

<h3>Key Idea</h3>

<pre>
Find the node
     ↓
┌─────────────────────────┐
│                         │
Leaf     One Child     Two Children
 ↓          ↓               ↓
NULL     Return child    Inorder Successor
                         ↓
                    Copy its value
                         ↓
                    Delete successor
</pre>

<h3>Why Inorder Successor?</h3>

<pre>
For:

        5
       / \
      3   8
         /
        6

If deleting 5:

Right subtree = [6, 8]

Smallest value = 6

So:

        6
       / \
      3   8

BST property is maintained.
</pre>

<h3>Complexity</h3>

<pre>
TC: O(h)

Searching + finding successor takes O(h).

Balanced BST → O(log n)
Skewed BST   → O(n)

SC: O(h)

Due to recursion.

Balanced BST → O(log n)
Skewed BST   → O(n)
</pre>

<hr>

<p><strong>Pattern:</strong> BST / Search / Inorder Successor / Recursion</p>

<p><strong>Key Idea:</strong> Find the node using BST property. If it has two children, replace its value with the smallest value from its right subtree and then delete that successor.</p>
