<h2>Delete the Middle Node of a Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Use the slow and fast pointer technique.

- slow moves one step
- fast moves two steps

When fast reaches the end, slow reaches the
middle node.

To delete the middle node, keep a pointer to
the node before slow and skip slow.
</pre>

<h3>Approach</h3>

<ol>
  <li>If the list has only one node, return <code>NULL</code>.</li>
  <li>Initialize <code>slow = head</code>, <code>fast = head</code>, and <code>prev = NULL</code>.</li>
  <li>Move <code>slow</code> one step and <code>fast</code> two steps while keeping <code>prev</code> behind slow.</li>
  <li>When the loop ends, <code>slow</code> points to the middle node.</li>
  <li>Set <code>prev-&gt;next = slow-&gt;next</code> and delete <code>slow</code>.</li>
  <li>Return <code>head</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Fast &amp; Slow Pointers / Deletion</p>

<p><strong>Key Idea:</strong> Use slow and fast pointers to reach the middle while keeping the previous node so the middle can be bypassed.</p>
