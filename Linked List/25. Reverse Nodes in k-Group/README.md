<h2>Reverse Nodes in k-Group</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<h3>Key Observation</h3>

<pre>
Reverse the linked list k nodes at a time.

Before reversing a group:
- Make sure at least k nodes are available.
- Reverse exactly those k nodes.
- Connect the reversed group with the previous and next groups.

If fewer than k nodes remain at the end, leave them unchanged.
</pre>

<h3>Approach</h3>

<ol>
  <li>Use a dummy node before the head to simplify connections.</li>
  <li>Find the kth node from the current group.</li>
  <li>If fewer than k nodes remain, stop and leave them unchanged.</li>
  <li>Reverse the k nodes in-place.</li>
  <li>Connect the previous group's tail to the reversed group's head.</li>
  <li>Connect the reversed group's tail to the next group.</li>
  <li>Repeat until the list is processed.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Reversal / Grouping / Pointer Manipulation</p>

<p><strong>Key Idea:</strong> Check for k nodes, reverse exactly k nodes, reconnect them, and leave the final incomplete group unchanged.</p>
