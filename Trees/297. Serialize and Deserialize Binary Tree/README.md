<h2>297. Serialize and Deserialize Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<h3>Key Observation</h3>

<pre>
Use Level Order Traversal (BFS)

Normal BFS:
Root → Left → Right

But we also store NULL nodes as "#"
to preserve the exact tree structure.
</pre>

<p>For every non-NULL node, push <strong>both left and right children</strong> into the queue, even if they are NULL.</p>

<h3>Serialize</h3>

<pre>
If node == NULL:
    store "#"

Otherwise:
    store node->val
    push left child
    push right child
</pre>

<p>Example:</p>

<pre>
        1
       / \
      2   3
         / \
        4   5

Serialized:

1,2,3,#,#,4,5,#,#,#,#,
</pre>

<h3>Why Store NULL?</h3>

<p>NULL markers are necessary to preserve the exact structure of the tree.</p>

<pre>
    1
   /
  2

Without NULL:
1,2

We cannot know whether 2 is the
left or right child.

With NULL:
1,2,#,#,#,
</pre>

<h3>Deserialize</h3>

<ul>
<li>Read the first value and create the root.</li>
<li>Put the root into a queue.</li>
<li>For each node, read the next value for its left child.</li>
<li>Read the next value for its right child.</li>
<li>If the value is <code>#</code>, keep the child NULL.</li>
<li>Otherwise create the child and push it into the queue.</li>
</ul>

<h3>Important Point</h3>

<pre>
Non-NULL node:
    store value
    push left
    push right

NULL node:
    store "#"
    continue

The "continue" prevents accessing:
node->left / node->right
when node is NULL.
</pre>

<h3>Key Idea</h3>

<pre>
Serialize:
Tree → BFS → String

Deserialize:
String → BFS → Tree

NULL → "#"

The NULL markers preserve the
complete structure of the tree.
</pre>

<h3>Complexity</h3>

<pre>
TC: O(n)

Each node is processed once during serialization
and once during deserialization.

SC: O(n)

Queue and serialized string require O(n) space.
</pre>

<hr>

<p><strong>Pattern:</strong> Binary Tree / BFS / Queue / Serialization & Deserialization</p>

<p><strong>Key Idea:</strong> Use level-order traversal and store NULL children as "#" so the exact tree structure can be reconstructed.</p>
