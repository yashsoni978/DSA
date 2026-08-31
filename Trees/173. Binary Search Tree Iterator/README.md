<h2>173. Binary Search Tree Iterator</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<p>A BST's inorder traversal gives elements in <strong>sorted ascending order</strong>.</p>

<pre>
BST

        7
       / \
      3   15
         /  \
        9    20

Inorder:
3 → 7 → 9 → 15 → 20
</pre>

<p>The iterator needs to return these values one by one using <code>next()</code>.</p>

<h3>Approach</h3>

<p>Instead of storing the complete inorder traversal, use a <strong>stack</strong> to simulate inorder traversal.</p>

<ul>
<li>Initially, push the entire left chain of the root into the stack.</li>
<li>The top of the stack is always the smallest unvisited node.</li>
<li>In <code>next()</code>, pop the top node.</li>
<li>If that node has a right child, push the left chain of its right subtree.</li>
<li><code>hasNext()</code> simply checks whether the stack is empty.</li>
</ul>

<h3>Why Stack?</h3>

<pre>
Inorder:

LEFT → ROOT → RIGHT

We first go as far LEFT as possible.

        7
       /
      3
     /
    1

Stack:

7
3
1  ← top

Pop 1
Then pop 3
Then pop 7
</pre>

<p>When a node is popped, its right subtree becomes the next part that needs to be processed.</p>

<h3>Code</h3>

<pre>
class BSTIterator {
private:
    stack&lt;TreeNode*&gt; st;

    void pushLeft(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root-&gt;left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if(node-&gt;right)
            pushLeft(node-&gt;right);

        return node-&gt;val;
    }

    bool hasNext() {
        return !st.empty();
    }
};
</pre>

<h3>Example</h3>

<pre>
        7
       / \
      3   15
         /  \
        9    20
</pre>

<p>Initially:</p>

<pre>
pushLeft(7)

Stack:
7
3  ← top
</pre>

<p><code>next()</code>:</p>

<pre>
pop 3
return 3
</pre>

<p>Next:</p>

<pre>
pop 7
return 7

7 has right child 15

pushLeft(15)

Stack:
15
9  ← top
</pre>

<p>Next values:</p>

<pre>
9 → 15 → 20
</pre>

<p>So the iterator produces:</p>

<pre>
3 → 7 → 9 → 15 → 20
</pre>

<h3>Key Idea</h3>

<pre>
BST
 ↓
Inorder = Sorted Order
 ↓
Use Stack to simulate inorder
 ↓
Top of stack = Next smallest element
</pre>

<h3>Complexity</h3>

<pre>
Constructor: O(h)

next(): O(h) worst case

Amortized next(): O(1)

hasNext(): O(1)

SC: O(h)

where h = height of the BST.
</pre>

<hr>

<p><strong>Pattern:</strong> BST / Inorder Traversal / Stack / Iterator</p>

<p><strong>Key Idea:</strong> Keep the leftmost unvisited path in a stack. Every time <code>next()</code> pops a node, process the leftmost path of its right subtree.</p>
