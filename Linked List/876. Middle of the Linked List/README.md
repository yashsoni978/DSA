<h2>Middle of the Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Use two pointers:
- slow moves one step at a time
- fast moves two steps at a time

When fast reaches the end, slow will be at the middle.
For an even-sized list, slow reaches the second middle node.
</pre>

<h3>Approach</h3>

<ol>
  <li>Initialize <code>slow = head</code> and <code>fast = head</code>.</li>
  <li>Move <code>slow</code> by one node and <code>fast</code> by two nodes.</li>
  <li>Continue while <code>fast</code> and <code>fast-&gt;next</code> exist.</li>
  <li>Return <code>slow</code>, which points to the middle node.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Fast &amp; Slow Pointers</p>

<p><strong>Key Idea:</strong> Fast moves twice as quickly as slow, so when fast reaches the end, slow is at the middle.</p>
