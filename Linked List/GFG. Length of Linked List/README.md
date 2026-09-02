<h2>Length of Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Basic-green" alt="Difficulty: Basic"/>

<hr>

<h3>Key Observation</h3>

<pre>
head → 1 → 2 → 3 → 4 → 5 → NULL

Count each node while traversing the linked list.
</pre>

<p>Start from the <strong>head</strong> and move through every node using the <code>next</code> pointer. Increment the count for each node visited.</p>

<h3>Approach</h3>

<ol>
  <li>Initialize <code>count = 0</code>.</li>
  <li>Start a pointer from <strong>head</strong>.</li>
  <li>While the pointer is not <code>NULL</code>, increment <code>count</code>.</li>
  <li>Move the pointer to the next node.</li>
  <li>Return <code>count</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

Every node is visited exactly once.

SC: O(1)

Only a pointer and a counter are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Traversal / Counting</p>

<p><strong>Key Idea:</strong> Traverse the linked list from head to NULL and increment a counter for every node visited.</p>
