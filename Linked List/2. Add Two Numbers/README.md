<h2>Add Two Numbers</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
l1: 2 → 4 → 3
l2: 5 → 6 → 4

342 + 465 = 807

Result:
7 → 0 → 8
</pre>

<p>
The digits are stored in <strong>reverse order</strong>, so we can add the two
linked lists directly from their heads while maintaining a <strong>carry</strong>.
</p>

<h3>Approach</h3>

<ol>
  <li>Create a dummy node to simplify result-list construction.</li>
  <li>Traverse both lists while either list has nodes or a carry remains.</li>
  <li>Add the current digits and the carry.</li>
  <li>Store <code>sum % 10</code> as the new node's value.</li>
  <li>Update carry using <code>sum / 10</code>.</li>
  <li>Move the pointers forward and continue.</li>
  <li>Return <code>dummy-&gt;next</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(max(n, m))

Each node of both lists is processed once.

SC: O(max(n, m))

The result list requires at most max(n, m) + 1 nodes.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Addition / Carry / Dummy Node</p>

<p><strong>Key Idea:</strong> Add corresponding digits while carrying the overflow to the next position.</p>
