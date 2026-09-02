<h2>Doubly Linked List from an Array</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Array:
[1, 2, 3, 4]

Doubly Linked List:
NULL ← 1 ⇄ 2 ⇄ 3 ⇄ 4 → NULL
</pre>

<p>Each array element becomes a new node. For every new node, we maintain both <code>next</code> and <code>prev</code> connections.</p>

<h3>Approach</h3>

<ol>
  <li>Create the first node and make it the <strong>head</strong>.</li>
  <li>Keep a <code>tail</code> pointer pointing to the last node.</li>
  <li>For every remaining array element, create a new node.</li>
  <li>Connect <code>tail-&gt;next</code> to the new node.</li>
  <li>Connect the new node's <code>prev</code> to <code>tail</code>.</li>
  <li>Move <code>tail</code> to the newly created node.</li>
  <li>Return the <strong>head</strong>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

Each array element is processed exactly once.

SC: O(n)

A new DLL node is created for every array element.
</pre>

<hr>

<p><strong>Pattern:</strong> Doubly Linked List / Array Traversal / Node Creation / Pointer Manipulation</p>

<p><strong>Key Idea:</strong> Create one node for each array element and connect consecutive nodes using both <code>next</code> and <code>prev</code> pointers.</p>
