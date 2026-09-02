<h2>Delete in a Doubly Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
1 ⇄ 3 ⇄ 4 ⇄ 3
        ↑
      delete

After:
1 ⇄ 3 ⇄ 3
</pre>

<p>
To delete the node at the <strong>xth position</strong>, find that node and reconnect
its previous and next nodes.
</p>

<h3>Approach</h3>

<ol>
  <li>Traverse the list until reaching the <code>xth</code> node.</li>
  <li>If it is the only node, return <code>NULL</code>.</li>
  <li>If it is the head, move the head to the next node and update its <code>prev</code>.</li>
  <li>If it is the tail, update the previous node's <code>next</code> to <code>NULL</code>.</li>
  <li>For a middle node, connect <code>prev</code> and <code>next</code> directly.</li>
  <li>Disconnect and delete the target node.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

Traverse the list to reach the xth node.

SC: O(1)

Only constant extra pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Doubly Linked List / Deletion / Pointer Manipulation / 1-Based Indexing</p>

<p><strong>Key Idea:</strong> Find the target node and connect its previous and next nodes, handling head and tail separately.</p>
