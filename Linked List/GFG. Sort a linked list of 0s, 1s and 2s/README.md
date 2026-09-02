<h2>Sort a Linked List of 0s, 1s and 2s</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Input:
1 → 2 → 2 → 1 → 2 → 0 → 2

Create 3 separate chains:

0-list: 0
1-list: 1 → 1
2-list: 2 → 2 → 2 → 2

Connect them:

0 → 1 → 1 → 2 → 2 → 2 → 2
</pre>

<p>
Since the list contains only <strong>0, 1, and 2</strong>, maintain three separate
linked lists for each value. Traverse the original list once and attach every node
to its corresponding list.
</p>

<h3>Approach</h3>

<ol>
  <li>Create dummy nodes for the <code>0</code>, <code>1</code>, and <code>2</code> lists.</li>
  <li>Traverse the original linked list.</li>
  <li>Attach each node to the list corresponding to its value.</li>
  <li>Connect the <code>0</code> list to the <code>1</code> list.</li>
  <li>Connect the <code>1</code> list to the <code>2</code> list.</li>
  <li>Return the first actual node of the <code>0</code> list.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

The list is traversed once.

SC: O(1)

Only constant extra pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Segregation / Dummy Nodes / In-Place Rearrangement</p>

<p><strong>Key Idea:</strong> Maintain separate chains for 0s, 1s, and 2s, then connect the three chains.</p>
