<h2>Search in Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
head → 1 → 2 → 3 → 4 → NULL

Check each node's value against the given key.
</pre>

<p>Since a linked list does not support direct indexing, we need to <strong>traverse the list sequentially</strong> and compare each node's value with the key.</p>

<h3>Approach</h3>

<ol>
  <li>Start from the <strong>head</strong> of the linked list.</li>
  <li>For every node, check if <code>node-&gt;data == key</code>.</li>
  <li>If a match is found, return <code>true</code>.</li>
  <li>Otherwise, move to the next node.</li>
  <li>If <code>NULL</code> is reached, return <code>false</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

In the worst case, every node is visited.

SC: O(1)

Only a traversal pointer is used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Traversal / Linear Search</p>

<p><strong>Key Idea:</strong> Traverse the linked list from head to NULL and compare each node's value with the given key.</p>
