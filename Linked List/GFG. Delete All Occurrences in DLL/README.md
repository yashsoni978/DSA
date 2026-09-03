<h2>Delete All Occurrences in DLL</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Traverse the DLL and delete every node whose data == x.

For each matching node:
- Connect its previous node to its next node.
- Connect its next node back to its previous node.
- If it is the head, move head to the next node.

Save the next node before deleting the current node
so traversal can continue safely.
</pre>

<h3>Approach</h3>

<ol>
  <li>Traverse the list using a pointer <code>temp</code>.</li>
  <li>If <code>temp-&gt;data == x</code>, store <code>temp-&gt;next</code>.</li>
  <li>Update the <code>prev</code> and <code>next</code> pointers of neighboring nodes.</li>
  <li>If the node is the head, update <code>head</code>.</li>
  <li>Delete the current node and continue from the saved next node.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Doubly Linked List / Deletion / Pointer Manipulation</p>

<p><strong>Key Idea:</strong> For every matching node, bypass it by connecting its previous and next nodes, while carefully handling the head.</p>
