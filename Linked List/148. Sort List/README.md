<h2>148. Sort List</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
A linked list cannot be efficiently sorted using
index-based sorting like arrays.

Use Merge Sort:
Split the list into two halves, recursively sort both,
then merge the two sorted halves.
</pre>

<h3>Approach</h3>

<ol>
  <li>Find the middle using slow and fast pointers.</li>
  <li>Split the list into two halves.</li>
  <li>Recursively sort both halves.</li>
  <li>Merge the two sorted linked lists.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(N log N)

SC: O(log N) → recursion stack
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Merge Sort / Divide & Conquer</p>

<p><strong>Key Idea:</strong> Split → Sort both halves → Merge.</p>
