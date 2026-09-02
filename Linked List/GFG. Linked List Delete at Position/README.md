<h2>Linked List Delete at Position</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Positions are 1-based.

1 → 2 → 3 → 4 → 5
            ↑
          delete

After deletion:

1 → 2 → 3 → 5
</pre>

<p>To delete a node, reach the node <strong>just before</strong> the target and change its <code>next</code> pointer to skip the target node.</p>

<h3>Approach</h3>

<ol>
  <li>If <code>x == 1</code>, delete the head and return the second node.</li>
  <li>Otherwise, traverse until reaching the node at position <code>x - 1</code>.</li>
  <li>Store the node at position <code>x</code> temporarily.</li>
  <li>Update <code>prev-&gt;next</code> to skip the target node.</li>
  <li>Delete the target node and return the updated head.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

In the worst case, we traverse up to the last node.

SC: O(1)

Only a few pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Traversal / Deletion / 1-Based Indexing</p>

<p><strong>Key Idea:</strong> Reach the node before the target, bypass the target by changing the <code>next</code> pointer, and handle head deletion separately.</p>
