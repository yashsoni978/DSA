<h2>Linked List Cycle</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Use two pointers:
- slow moves one step
- fast moves two steps

If a cycle exists, fast and slow will eventually
meet at the same node.

If fast reaches NULL, there is no cycle.
</pre>

<h3>Approach</h3>

<ol>
  <li>Initialize <code>slow = head</code> and <code>fast = head</code>.</li>
  <li>Move <code>slow</code> one step and <code>fast</code> two steps.</li>
  <li>If <code>slow == fast</code>, a cycle exists.</li>
  <li>If <code>fast == NULL</code> or <code>fast-&gt;next == NULL</code>, no cycle exists.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Fast &amp; Slow Pointers / Cycle Detection</p>

<p><strong>Key Idea:</strong> In a cycle, the faster pointer eventually catches the slower pointer.</p>
