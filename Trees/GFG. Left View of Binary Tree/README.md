<h2>Left View of Binary Tree</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>The <strong>left view</strong> contains the first node visible at every level when the binary tree is viewed from the left side.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>BFS (Level Order Traversal)</strong> with a queue.</li>
<li>Process the tree level by level.</li>
<li>For every level, the <strong>first node</strong> encountered is part of the left view.</li>
<li>Add that node to the answer.</li>
<li>Then process the remaining nodes of that level.</li>
</ul>

<h3>Example</h3>

<pre>
        1
       / \
      2   3
     / \
    4   5

Level 1 → 1
Level 2 → 2
Level 3 → 4

Left View:
[1, 2, 4]
</pre>

<h3>Key Idea</h3>

<pre>
BFS + Level Order

First node of every level = Left View
</pre>

<h3>Complexity</h3>

<p><strong>TC: O(n)</strong></p>

<p>Every node is visited exactly once.</p>

<p><strong>SC: O(n)</strong></p>

<p>The queue can contain up to O(n) nodes in the worst case.</p>

<hr>

<p><strong>Pattern:</strong> Binary Tree / BFS / Level Order Traversal</p>

<p><strong>Key Idea:</strong> Perform BFS and take the first node from every level.</p>
