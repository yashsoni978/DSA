<h2>Insertion in a Doubly Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Before:
1 ⇄ 2 ⇄ 3 ⇄ 4
        ↑
       p=2

Insert 6 after node 3:

After:
1 ⇄ 2 ⇄ 3 ⇄ 6 ⇄ 4
            ↑
          new node
</pre>

<p>
Traverse to the <strong>pth node</strong> (0-based), then insert the new node
between the current node and its next node.
</p>

<h3>Approach</h3>

<ol>
  <li>Traverse the list until reaching the <code>pth</code> node.</li>
  <li>Create a new node with value <code>x</code>.</li>
  <li>Store the current node's next node.</li>
  <li>Set the new node's <code>prev</code> to the current node.</li>
  <li>Set the new node's <code>next</code> to the stored next node.</li>
  <li>Update the current node's <code>next</code> to the new node.</li>
  <li>If a next node exists, update its <code>prev</code> to the new node.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

Traverse up to the pth node.

SC: O(1)

Only the new node and constant pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Doubly Linked List / Insertion / Pointer Manipulation / 0-Based Indexing</p>

<p><strong>Key Idea:</strong> Insert the new node between the pth node and its next node by correctly updating all four relevant pointers.</p>
