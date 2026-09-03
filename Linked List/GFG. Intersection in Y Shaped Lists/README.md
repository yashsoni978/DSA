<h2>Intersection in Y Shaped Lists</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
The two lists eventually share the same nodes.

Use two pointers:
- p1 starts at head1
- p2 starts at head2
- When a pointer reaches NULL, move it to the other head.

This makes both pointers travel the same total distance,
so they meet at the intersection node.
</pre>

<h3>Approach</h3>

<ol>
  <li>Initialize <code>p1 = head1</code> and <code>p2 = head2</code>.</li>
  <li>Move both pointers one node at a time.</li>
  <li>If <code>p1</code> reaches NULL, move it to <code>head2</code>.</li>
  <li>If <code>p2</code> reaches NULL, move it to <code>head1</code>.</li>
  <li>Continue until <code>p1 == p2</code>.</li>
  <li>Return the common node where they meet.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n + m)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Two Pointers / Intersection</p>

<p><strong>Key Idea:</strong> Switching heads when reaching NULL makes both pointers cover the same total distance, so they meet at the intersection.</p>
