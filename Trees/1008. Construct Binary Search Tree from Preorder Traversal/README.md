<h2>1008. Construct Binary Search Tree from Preorder Traversal</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Preorder Traversal:

Root → Left → Right
</pre>

<p>The <strong>first element</strong> of preorder is always the root.</p>

<p>Since it is a BST:</p>

<pre>
Values smaller than root → LEFT subtree
Values greater than root → RIGHT subtree
</pre>

<h3>Approach</h3>

<ul>
<li>Take the current preorder element as the root.</li>
<li>Maintain a <strong>maximum allowed value (upper bound)</strong>.</li>
<li>If the next preorder value is greater than the bound, it does not belong to the current subtree.</li>
<li>Build the left subtree with <code>bound = root-&gt;val</code>.</li>
<li>Build the right subtree with the same bound.</li>
<li>Move the preorder index forward whenever a node is created.</li>
</ul>

<h3>Example</h3>

<pre>
Preorder = [8, 5, 1, 7, 10, 12]

Start:

8
↓
Root = 8

Next = 5 &lt; 8
→ Left subtree

Next = 1 &lt; 5
→ Left of 5

Next = 7 &gt; 5
→ Right of 5

Next = 10 &gt; 8
→ Right of 8

Next = 12 &gt; 10
→ Right of 10
</pre>

<p>Result:</p>

<pre>
        8
       / \
      5   10
     / \    \
    1   7    12
</pre>

<h3>Code</h3>

<pre>
class Solution {
private:
    TreeNode* build(vector&lt;int&gt;&amp; preorder, int&amp; i, long long bound) {
        if(i == preorder.size() || preorder[i] &gt; bound)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);

        root-&gt;left = build(preorder, i, root-&gt;val);

        root-&gt;right = build(preorder, i, bound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector&lt;int&gt;&amp; preorder) {
        int i = 0;
        return build(preorder, i, LLONG_MAX);
    }
};
</pre>

<h3>Why Does the Bound Work?</h3>

<pre>
Suppose:

        8
       /
      5

When building LEFT of 8:

Allowed values:
(-∞, 8)

So 10 cannot belong to this subtree.

When preorder[i] = 10:

10 &gt; 8
   ↓
Stop building this subtree.

The parent call will handle 10
as the right subtree of 8.
</pre>

<h3>Key Idea</h3>

<pre>
Preorder gives ROOT first.

BST property tells us:

smaller → LEFT
greater → RIGHT

Use a bound to know when
the current subtree should stop.

Preorder:
ROOT → LEFT → RIGHT

Therefore:

Create root
    ↓
Build LEFT with root as bound
    ↓
Build RIGHT
</pre>

<h3>Complexity</h3>

<pre>
TC: O(n)

Each preorder element is processed once.

SC: O(h)

Recursion stack depends on tree height.

Balanced BST → O(log n)
Skewed BST   → O(n)
</pre>

<hr>

<p><strong>Pattern:</strong> BST / Preorder / Recursion / Upper Bound</p>

<p><strong>Key Idea:</strong> Preorder gives the root first, and the BST property lets us construct the tree using an upper bound without explicitly finding the left/right partition.</p>
