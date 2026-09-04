<h2>138. Copy List with Random Pointer</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Each node has two pointers:
next → next node
random → any node in the list (or NULL)

We need a deep copy where both pointers point
to the corresponding copied nodes.
</pre>

<h3>Approach</h3>

<ol>
  <li>Insert a copied node immediately after every original node.</li>
  <li>Set each copied node's random pointer using the original node's random pointer.</li>
  <li>Separate the copied nodes from the original list.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(N)

SC: O(1) → excluding the copied list
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Deep Copy / Pointer Manipulation</p>

<p><strong>Key Idea:</strong> Place the copy beside the original → set random → separate.</p>
