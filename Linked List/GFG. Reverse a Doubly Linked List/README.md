<h2>Reverse a Doubly Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
NULL ← 3 ⇄ 4 ⇄ 5 → NULL

After:
NULL ← 5 ⇄ 4 ⇄ 3 → NULL
                  ↑
                head
</pre>

<p>
For every node, <strong>swap its <code>next</code> and <code>prev</code> pointers</strong>.
After swapping, move to the node that was originally next. The last processed node
becomes the new head.
</p>

<h3>Approach</h3>

<ol>
  <li>Start from the head.</li>
  <li>For each node, swap its <code>next</code> and <code>prev</code> pointers.</li>
  <li>Move to the new <code>prev</code> pointer, which was the original <code>next</code>.</li>
  <li>Keep updating the head to the current node.</li>
  <li>Return the final head.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

Each node is visited once.

SC: O(1)

Only constant extra pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Doubly Linked List / Reversal / Pointer Manipulation</p>

<p><strong>Key Idea:</strong> Swap <code>next</code> and <code>prev</code> for every node; the last processed node becomes the new head.</p>
