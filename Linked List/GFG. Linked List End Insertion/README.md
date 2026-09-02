<h2>Linked List End Insertion</h2>

<img src="https://img.shields.io/badge/Difficulty-Basic-green" alt="Difficulty: Basic"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
head → 1 → 2 → 3 → 4 → 5 → NULL

Insert 6 at the end:

After:
head → 1 → 2 → 3 → 4 → 5 → 6 → NULL
</pre>

<p>To insert at the end, traverse the list until the <strong>last node</strong>, then connect the new node to it.</p>

<h3>Approach</h3>

<ol>
  <li>Create a new node with value <code>x</code>.</li>
  <li>If the list is empty, make the new node the <strong>head</strong>.</li>
  <li>Otherwise, traverse until <code>current-&gt;next == NULL</code>.</li>
  <li>Set the last node's <code>next</code> to the new node.</li>
  <li>Return the original <code>head</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

We may need to traverse the entire linked list
to reach the last node.

SC: O(1)

Only one new node and a traversal pointer are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Insertion / Traversal / Tail</p>

<p><strong>Key Idea:</strong> Traverse to the last node and connect the new node to its <code>next</code> pointer. If the list is empty, the new node becomes the head.</p>
