<h2>106. Construct Binary Tree from Inorder and Postorder Traversal</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Inorder:   Left → Root → Right
Postorder: Left → Right → Root
</pre>

<p>Therefore, the <strong>last element of postorder is always the root</strong>.</p>

<p>Find this root in the inorder array:</p>

<pre>
Inorder:

[ LEFT | ROOT | RIGHT ]
          ↑
        root

Everything before root → Left subtree
Everything after root  → Right subtree
</pre>

<h3>Important Difference from Problem 105</h3>

<p>In Problem 105, we took the root from the <strong>beginning of preorder</strong>.</p>

<p>Here, we take the root from the <strong>end of postorder</strong>.</p>

<pre>
Preorder  → first element = Root

Postorder → last element  = Root
</pre>

<p>When constructing recursively from postorder, build the <strong>right subtree first</strong>, then the left subtree, because postorder is:</p>

<pre>
Left → Right → Root

We consume it from right to left:

Root → Right → Left
</pre>

<h3>Approach</h3>

<ul>
<li>Store every inorder value's index in a map.</li>
<li>Start from the last element of postorder.</li>
<li>Create that element as the root.</li>
<li>Find its position in inorder.</li>
<li>Elements to the right form the right subtree.</li>
<li>Elements to the left form the left subtree.</li>
<li>Recursively build <strong>right first</strong>, then left.</li>
</ul>

<h3>Example</h3>

<pre>
Inorder   = [9, 3, 15, 20, 7]
Postorder = [9, 15, 7, 20, 3]

Last postorder element = 3
                         ↓
                       ROOT

Inorder:
[9] [3] [15,20,7]
 ↑    ↑       ↑
left root    right
</pre>

<p>Then <code>20</code> becomes the root of the right subtree, and the same process continues.</p>

<h3>Key Idea</h3>

<pre>
Postorder → Last element gives ROOT
Inorder   → ROOT position divides LEFT and RIGHT

Since postorder is processed backwards:

ROOT → RIGHT → LEFT

Therefore:
Build RIGHT first
Build LEFT second
</pre>

<h3>Complexity</h3>

<pre>
TC: O(n log n)

Each node is processed once and map lookup takes O(log n).

SC: O(n)

Map stores O(n) elements and recursion can take O(n)
space in the worst case.
</pre>

<hr>

<p><strong>Pattern:</strong> Binary Tree / Recursion / Inorder + Postorder / Hash Map</p>

<p><strong>Key Idea:</strong> The last element of postorder is the root, while inorder tells us where to split the left and right subtrees.</p>
