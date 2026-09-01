<h2>99. Recover Binary Search Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<p>A BST's inorder traversal is always sorted.</p>

<pre>
Valid BST:

        3
       / \
      1   4
         /
        2

Inorder:
1 → 2 → 3 → 4
</pre>

<p>Two nodes in the BST have been swapped. Therefore, the inorder traversal will contain one or two <strong>inversions</strong> where:</p>

<pre>
previous value &gt; current value
</pre>

<p>These violations help us identify the two swapped nodes.</p>

<h3>Approach</h3>

<ul>
<li>Perform inorder traversal.</li>
<li>Keep track of the previous node.</li>
<li>Whenever <code>prev-&gt;val &gt; root-&gt;val</code>, we found a violation.</li>
<li>For the first violation, store <code>first = prev</code> and <code>middle = root</code>.</li>
<li>If another violation occurs, store <code>last = root</code>.</li>
<li>At the end, swap the appropriate two node values.</li>
</ul>

<h3>Why First, Middle and Last?</h3>

<p>There are two possible situations.</p>

<h4>Case 1: Swapped nodes are adjacent in inorder</h4>

<pre>
Correct:
1 2 3 4

Swapped:
1 3 2 4
    ↑ ↑
   first middle
</pre>

<p>There is only one violation:</p>

<pre>
3 &gt; 2
</pre>

<p>So swap:</p>

<pre>
first ↔ middle
</pre>

<h4>Case 2: Swapped nodes are not adjacent</h4>

<pre>
Correct:
1 2 3 4 5

Swapped:
1 4 3 2 5
    ↑   ↑
  first last
</pre>

<p>There are two violations:</p>

<pre>
4 &gt; 3
3 &gt; 2
</pre>

<p>So swap:</p>

<pre>
first ↔ last
</pre>

<h3>Code</h3>

<pre>
class Solution {
private:
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if(!root) return;

        inorder(root-&gt;left);

        // Detect violation
        if(prev && prev-&gt;val &gt; root-&gt;val) {

            // First violation
            if(!first) {
                first = prev;
                middle = root;
            }
            // Second violation
            else {
                last = root;
            }
        }

        prev = root;

        inorder(root-&gt;right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);

        if(last) {
            // Non-adjacent nodes
            swap(first-&gt;val, last-&gt;val);
        }
        else {
            // Adjacent nodes
            swap(first-&gt;val, middle-&gt;val);
        }
    }
};
</pre>

<h3>Example</h3>

<pre>
        3
       / \
      1   4
         /
        2

Inorder:
1 → 3 → 2 → 4

Violation:
3 &gt; 2

first  = 3
middle = 2
last   = NULL

Swap 3 and 2:

        2
       / \
      1   4
         /
        3

Inorder:
1 → 2 → 3 → 4
</pre>

<h3>Key Idea</h3>

<pre>
BST
 ↓
Inorder must be sorted
 ↓
Find where prev &gt; current
 ↓
First violation:
    first = prev
    middle = current

Second violation:
    last = current

If last exists:
    swap(first, last)

Otherwise:
    swap(first, middle)
</pre>

<h3>Complexity</h3>

<pre>
TC: O(n)

Every node is visited once.

SC: O(h)

Recursion stack depends on tree height.

Balanced BST → O(log n)
Skewed BST   → O(n)
</pre>

<hr>

<p><strong>Pattern:</strong> BST / Inorder Traversal / Sorted Order / Detect Inversions</p>

<p><strong>Key Idea:</strong> Since a valid BST has sorted inorder traversal, the two swapped nodes can be identified by finding the one or two places where <code>prev-&gt;val &gt; current-&gt;val</code>.</p>
