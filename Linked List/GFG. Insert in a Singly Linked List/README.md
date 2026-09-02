<h2>Insert in a Singly Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
1 → 3 → NULL

pos = 2, val = 5

After:
1 → 5 → 3 → NULL
</pre>

<p>Since the position is <strong>1-based</strong>, position <code>1</code> means inserting at the head. For any other position, reach the node at <code>pos - 1</code> and adjust the pointers.</p>

<h3>Approach</h3>

<ol>
  <li>Create a new node with value <code>val</code>.</li>
  <li>If <code>pos == 1</code>, connect the new node to the current head and make it the new head.</li>
  <li>Otherwise, traverse to the node at position <code>pos - 1</code>.</li>
  <li>Set the new node's <code>next</code> to the next node.</li>
  <li>Set the previous node's <code>next</code> to the new node.</li>
  <li>Return the updated head.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

In the worst case, we traverse up to the end of the list.

SC: O(1)

Only one new node and a few pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Insertion / Pointer Manipulation / 1-Based Indexing</p>

<p><strong>Key Idea:</strong> For position 1, insert at the head. Otherwise, reach position <code>pos - 1</code> and insert the new node by adjusting the <code>next</code> pointers.</p>
