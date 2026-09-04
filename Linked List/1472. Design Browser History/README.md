<h2>1472. Design Browser History</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Browser history behaves like a Doubly Linked List.

current → current page
prev    → previous page
next    → forward page

When visiting a new URL, all forward history is discarded.
</pre>

<h3>Approach</h3>

<ol>
  <li>Create a doubly linked list with the homepage as the first node.</li>
  <li><strong>visit:</strong> Create a new node and connect it after current. Discard forward history.</li>
  <li><strong>back:</strong> Move current backward up to the given number of steps.</li>
  <li><strong>forward:</strong> Move current forward up to the given number of steps.</li>
</ol>

<h3>Complexity</h3>

<pre>
visit:   O(1)
back:    O(steps)
forward: O(steps)

Space: O(N)
</pre>

<hr>

<p><strong>Pattern:</strong> Doubly Linked List / Design / Navigation</p>

<p><strong>Key Idea:</strong> Use a DLL so moving backward and forward only requires pointer movement.</p>
