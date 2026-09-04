<h2>Remove Duplicates from a Sorted DLL</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Since the DLL is sorted, duplicate values will always
be adjacent.

Traverse the list and whenever the current node and
next node have the same value, delete the next node.
</pre>

<h3>Approach</h3>

<ol>
  <li>Start from the head.</li>
  <li>Compare <code>temp-&gt;data</code> with <code>temp-&gt;next-&gt;data</code>.</li>
  <li>If they are equal, remove the next node by updating both <code>next</code> and <code>prev</code> pointers.</li>
  <li>If they are different, move <code>temp</code> forward.</li>
  <li>Continue until the end of the list.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Doubly Linked List / Duplicate Removal / Traversal</p>

<p><strong>Key Idea:</strong> Because the list is sorted, duplicates are adjacent, so each duplicate can be removed in one traversal.</p>
