<h2>Odd Even Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
1 → 2 → 3 → 4 → 5

Odd nodes:  1 → 3 → 5
Even nodes: 2 → 4

After:
1 → 3 → 5 → 2 → 4
</pre>

<p>
The problem groups nodes based on their <strong>positions</strong>, not their values.
Keep separate pointers for the odd and even nodes, then connect the odd list to
the even list. The relative order within both groups must remain unchanged. :contentReference[oaicite:0]{index=0}
</p>

<h3>Approach</h3>

<ol>
  <li>Keep <code>odd</code> at the first node and <code>even</code> at the second node.</li>
  <li>Store the starting node of the even list as <code>evenHead</code>.</li>
  <li>Connect each odd node to the next odd node.</li>
  <li>Connect each even node to the next even node.</li>
  <li>Continue until there are no more pairs.</li>
  <li>Connect the end of the odd list to <code>evenHead</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

Each node is visited once.

SC: O(1)

Only constant extra pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Two Pointers / In-Place Rearrangement</p>

<p><strong>Key Idea:</strong> Build the odd-position and even-position chains in-place, then connect the odd chain to the even chain.</p>
