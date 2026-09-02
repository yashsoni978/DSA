<h2>Delete Head of Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
head → 1 → 2 → 3 → 4 → NULL

After deleting head:
head → 2 → 3 → 4 → NULL
</pre>

<p>The new head is simply the <strong>second node</strong> of the original linked list.</p>

<h3>Approach</h3>

<ol>
  <li>Store the original head in a temporary pointer.</li>
  <li>Move <code>head</code> to <code>head-&gt;next</code>.</li>
  <li>Set the original head to <code>NULL</code>.</li>
  <li>Return the new <code>head</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(1)

Only the head pointer is modified.

SC: O(1)

Only a temporary pointer is used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Head Manipulation / Deletion</p>

<p><strong>Key Idea:</strong> Move the head to the next node and set the original head to NULL.</p><h2>Delete Head of Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
head → 1 → 2 → 3 → 4 → NULL

After deleting head:
head → 2 → 3 → 4 → NULL
</pre>

<p>The new head is simply the <strong>second node</strong> of the original linked list.</p>

<h3>Approach</h3>

<ol>
  <li>Store the original head in a temporary pointer.</li>
  <li>Move <code>head</code> to <code>head-&gt;next</code>.</li>
  <li>Set the original head to <code>NULL</code>.</li>
  <li>Return the new <code>head</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(1)

Only the head pointer is modified.

SC: O(1)

Only a temporary pointer is used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Head Manipulation / Deletion</p>

<p><strong>Key Idea:</strong> Move the head to the next node and set the original head to NULL.</p>
