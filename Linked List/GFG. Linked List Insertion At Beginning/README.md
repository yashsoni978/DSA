<h2>Linked List Insertion At Beginning</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
head → 2 → 3 → 10 → NULL

Insert 1 at beginning:

After:
head → 1 → 2 → 3 → 10 → NULL
</pre>

<p>To insert a node at the beginning, create a new node, point it to the current <strong>head</strong>, and then make the new node the new head.</p>

<h3>Approach</h3>

<ol>
  <li>Create a new node with value <code>x</code>.</li>
  <li>Set the new node's <code>next</code> to the current <code>head</code>.</li>
  <li>Update <code>head</code> to point to the new node.</li>
  <li>Return the updated <code>head</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(1)

No traversal is required.

SC: O(1)

Only one new node is created.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Insertion / Head Manipulation</p>

<p><strong>Key Idea:</strong> Create a new node, connect it to the current head, and make it the new head.</p>
