<h2>105. Construct Binary Tree from Preorder and Inorder Traversal</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the <strong>preorder</strong> and <strong>inorder</strong> traversal of a binary tree, construct and return the original binary tree.</p>

<h3>Key Observation</h3>

<pre>
Preorder: Root → Left → Right
Inorder:  Left → Root → Right
</pre>

<p>So, the <strong>first element of preorder is always the root</strong>.</p>

<p>Find this root in the inorder array:</p>

<pre>
        root
       /    \
   left     right

Inorder:
[ LEFT | ROOT | RIGHT ]
          ↑
       root index
</pre>

<p>The elements before the root belong to the <strong>left subtree</strong>, and elements after the root belong to the <strong>right subtree</strong>.</p>

<h3>Approach</h3>

<ul>
<li>Take <code>preorder[preIndex]</code> as the current root.</li>
<li>Find the root's position in <code>inorder</code>.</li>
<li>Everything to the left belongs to the left subtree.</li>
<li>Everything to the right belongs to the right subtree.</li>
<li>Recursively construct both subtrees.</li>
<li>Use a <code>map</code> to store the inorder index of every value, avoiding a linear search.</li>
</ul>

<h3>Example</h3>

<pre>
Preorder = [3, 9, 20, 15, 7]
Inorder  = [9, 3, 15, 20, 7]

First preorder element = 3
                 ↓
             root = 3

Inorder:
[9] [3] [15,20,7]
 ↑    ↑       ↑
left root    right
</pre>

<p>Then recursively construct the left and right subtrees using the same logic.</p>

<h3>Key Idea</h3>

<pre>
Preorder → tells us WHAT is the root

Inorder → tells us WHERE the root divides
          left subtree and right subtree

        ↓

Recursively build the tree
</pre>

<h3>Complexity</h3>

<pre>
TC: O(n)

Each node is created/processed once and the unordered_map
gives O(1) average lookup for its inorder position.

SC: O(n)

unordered_map stores n elements and recursion can use O(n)
stack space in the worst case.
</pre>

<hr>

<p><strong>Pattern:</strong> Binary Tree / Recursion / Preorder + Inorder / Hash Map</p>

<p><strong>Key Idea:</strong> Preorder gives the root, while inorder tells us how to split the left and right subtrees.</p>
