<h2>Delete Head of Doubly Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
NULL ← 1 ⇄ 2 ⇄ 3 → NULL
       ↑
     head

After:
NULL ← 2 ⇄ 3 → NULL
       ↑
     head
</pre>

<p>In a doubly linked list, after deleting the head, the <strong>next node becomes the new head</strong>. Its <code>prev</code> pointer must be set to <code>NULL</code>.</p>

<h3>Approach</h3>

<ol>
  <li>Store the current head in a temporary pointer.</li>
  <li>Move <code>head</code> to <code>head-&gt;next</code>.</li>
  <li>Set the new head's <code>prev</code> to <code>NULL</code>.</li>
  <li>Disconnect the old head's pointers.</li>
  <li>Delete the old head.</li>
  <li>Return the new head.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(1)

Only the head node is modified.

SC: O(1)

Only a temporary pointer is used.
</pre>

<hr>

<p><strong>Pattern:</strong> Doubly Linked List / Head Deletion / Pointer Manipulation</p>

<p><strong>Key Idea:</strong> Move the head to the next node, set its <code>prev</code> to NULL, disconnect and delete the old head.</p>
