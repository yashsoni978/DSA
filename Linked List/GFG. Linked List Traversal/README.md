<h2>Linked List Traversal</h2>

<img src="https://img.shields.io/badge/Difficulty-Basic-green" alt="Difficulty: Basic"/>

<hr>

<h3>Key Observation</h3>

<pre>
Start from the head of the linked list
and keep moving to the next node.

head → next → next → next → NULL
</pre>

<p>At each node, print its value and move the pointer using <code>current = current-&gt;next</code>.</p>

<h3>Approach</h3>

<ol>
  <li>Initialize a pointer at the <strong>head</strong> of the linked list.</li>
  <li>While the pointer is not <code>NULL</code>, print the current node's value.</li>
  <li>Move the pointer to the next node.</li>
  <li>Stop when <code>NULL</code> is reached.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

Every node is visited exactly once.

SC: O(1)

Only one traversal pointer is used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Traversal / Pointer</p>

<p><strong>Key Idea:</strong> Start from the head and repeatedly move to the next node until reaching <code>NULL</code>.</p>
