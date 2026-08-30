<h2>Children Sum in a Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Check whether every <strong>non-leaf node</strong> satisfies:</p>

<pre>
node->data = left child value + right child value
</pre>

<p>A <code>NULL</code> child contributes <strong>0</strong>.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>DFS / Recursion</strong>.</li>
<li>If the node is <code>NULL</code> or a leaf, return <code>true</code>.</li>
<li>Calculate the value of the left and right children.</li>
<li>Check whether:</li>
</ul>

<pre>
root->data == leftValue + rightValue
</pre>

<ul>
<li>Then recursively check both subtrees.</li>
<li>If any node violates the property, return <code>false</code>.</li>
</ul>

<h3>Key Idea</h3>

<pre>
For every non-leaf:

        root
       /    \
    left    right

root->data == left->data + right->data
</pre>

<h3>Complexity</h3>

<p><strong>TC: O(n)</strong></p>

<p>Every node is visited once.</p>

<p><strong>SC: O(h)</strong></p>

<p>Recursion stack uses O(h), where h is the height of the tree. Worst case: O(n).</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / DFS / Recursion</p>

<p><strong>Key Idea:</strong> Check the children-sum condition at every non-leaf node and recursively validate both subtrees.</p>
