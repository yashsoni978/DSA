<h2>Add 1 to a Linked List Number</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Input:
4 → 5 → 6

456 + 1 = 457

Input:
9 → 9 → 9

999 + 1 = 1000
</pre>

<p>
Addition starts from the <strong>last digit</strong>, but a singly linked list
can only be traversed forward. Reverse the list, add <code>1</code> while
handling the carry, then reverse the list again.
</p>

<h3>Approach</h3>

<ol>
  <li>Reverse the linked list.</li>
  <li>Start with <code>carry = 1</code>.</li>
  <li>Add the carry to each digit from right to left.</li>
  <li>Store <code>sum % 10</code> in the current node.</li>
  <li>Update carry using <code>sum / 10</code>.</li>
  <li>Continue until all nodes are processed or carry becomes <code>0</code>.</li>
  <li>If a carry remains, create a new node with value <code>1</code>.</li>
  <li>Reverse the list again and return the head.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

The list is reversed twice and traversed once.

SC: O(1)

Only constant extra pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Reversal / Carry Propagation</p>

<p><strong>Key Idea:</strong> Reverse the list so addition can be performed from the least significant digit, then reverse it back.</p>
