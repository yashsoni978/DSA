<h2>662. Maximum Width of Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given the root of a binary tree, return the <strong>maximum width</strong> of the tree.</p>

<p>The width of a level is measured from the leftmost non-null node to the rightmost non-null node, including the positions of null nodes between them.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>BFS (Level Order Traversal)</strong>.</li>
<li>Assign an index to every node as if the tree were a complete binary tree.</li>
<li>For a node at index <code>i</code>:</li>
</ul>

<pre>
Left child  → 2 * i + 1
Right child → 2 * i + 2
</pre>

<ul>
<li>For each level, calculate:</li>
</ul>

<pre>
width = rightmost index - leftmost index + 1
</pre>

<li>Keep track of the maximum width.</li>
<li>To avoid very large indices, normalize indices at every level by subtracting the first index of that level.</li>
</ul>

<h3>Example</h3>

<pre>
        1
       / \
      2   3
     /     \
    4       5

Indices:

        1(0)
       /   \
    2(1)   3(2)
    /         \
 4(3)         5(6)

Level 3 width:
6 - 3 + 1 = 4

So maximum width = 4
</pre>

<h3>Key Idea</h3>

<pre>
BFS + Complete Binary Tree Indexing

width = rightIndex - leftIndex + 1
</pre>

<h3>Complexity</h3>

<p><strong>TC: O(n)</strong></p>

<p>Every node is visited exactly once.</p>

<p><strong>SC: O(n)</strong></p>

<p>The queue can contain O(n) nodes in the worst case.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / BFS / Queue / Indexing</p>

<p><strong>Key Idea:</strong> Give every node its position as if the tree were complete, then calculate the distance between the first and last node at each level.</p>
