<h2>Flattening a Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Each vertical list is already sorted, and the head nodes
are also sorted.

So, flatten the lists from right to left and merge the
current list with the already flattened list.

Use only the bottom pointer in the final list.
</pre>

<h3>Approach</h3>

<ol>
  <li>Recursively flatten the list starting from <code>head-&gt;next</code>.</li>
  <li>Merge the current vertical list with the flattened list.</li>
  <li>During merging, compare node values and connect nodes using <code>bottom</code>.</li>
  <li>Set <code>next</code> pointers to <code>NULL</code> so the final list uses only <code>bottom</code>.</li>
  <li>Return the merged list.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(N)

SC: O(k) recursion stack

N = total number of nodes
k = number of linked lists
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Merge / Recursion / Sorted Lists</p>

<p><strong>Key Idea:</strong> Flatten from right to left and repeatedly merge two sorted bottom-linked lists.</p>
