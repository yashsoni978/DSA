<h2>Rotate List</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Rotating right by k means moving the last k nodes
to the front.

Since k can be larger than the list length:
k = k % n

Make the list circular, then break it at the
new tail.
</pre>

<h3>Approach</h3>

<ol>
  <li>Find the length <code>n</code> and the tail of the list.</li>
  <li>Calculate <code>k = k % n</code>.</li>
  <li>If <code>k == 0</code>, return the original head.</li>
  <li>Connect the tail to the head to form a circular list.</li>
  <li>The new tail is the <code>(n - k)</code>th node.</li>
  <li>Set the node after the new tail as the new head.</li>
  <li>Break the circular connection.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Rotation / Circular Linked List</p>

<p><strong>Key Idea:</strong> Convert the list into a circle, find the new tail at position <code>n-k</code>, then break the circle.</p>
