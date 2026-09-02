<h2>Reverse Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
1 → 2 → 3 → 4 → 5 → NULL

After:
5 → 4 → 3 → 2 → 1 → NULL
</pre>

<p>
Reverse the linked list by changing the <code>next</code> pointer of each node
to point to its previous node. Use three pointers: <code>prev</code>,
<code>temp</code>, and <code>front</code>.
</p>

<h3>Approach</h3>

<ol>
  <li>Initialize <code>prev = NULL</code> and <code>temp = head</code>.</li>
  <li>Store the next node in <code>front</code>.</li>
  <li>Reverse the current node's pointer: <code>temp-&gt;next = prev</code>.</li>
  <li>Move <code>prev</code> and <code>temp</code> one step forward.</li>
  <li>Repeat until <code>temp</code> becomes <code>NULL</code>.</li>
  <li>Return <code>prev</code> as the new head.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

Each node is visited once.

SC: O(1)

Only constant extra pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Reversal / Pointer Manipulation</p>

<p><strong>Key Idea:</strong> Reverse each <code>next</code> pointer using <code>prev</code>, <code>temp</code>, and <code>front</code>.</p>
