<h2>Deletion at the End of a Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
head → 1 → 2 → 3 → 4 → 5 → NULL
                         ↑
                       tail

After:
head → 1 → 2 → 3 → 4 → NULL
</pre>

<p>To delete the tail, we need to reach the <strong>second-last node</strong> and make its <code>next</code> pointer <code>NULL</code>.</p>

<h3>Approach</h3>

<ol>
  <li>If the list is empty or contains only one node, handle it separately.</li>
  <li>Traverse the list until the <strong>second-last node</strong>.</li>
  <li>Store the current tail temporarily.</li>
  <li>Set the second-last node's <code>next</code> to <code>NULL</code>.</li>
  <li>Delete the old tail and return the head.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

In the worst case, we traverse the entire linked list
to reach the second-last node.

SC: O(1)

Only a few pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Traversal / Tail Deletion / Pointer Manipulation</p>

<p><strong>Key Idea:</strong> Traverse to the second-last node, set its <code>next</code> to NULL, and delete the original tail.</p>
