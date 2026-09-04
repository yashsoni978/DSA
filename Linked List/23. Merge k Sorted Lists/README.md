<h2>23. Merge k Sorted Lists</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<h3>Key Observation</h3>

<pre>
We have k sorted linked lists.

At any moment, the smallest node among the current
heads of all k lists should be added to the answer.

A Min Heap helps us efficiently find this smallest node.
</pre>

<h3>Approach</h3>

<ol>
  <li>Put the head of every non-empty list into a Min Heap.</li>
  <li>Extract the smallest node from the heap.</li>
  <li>Add it to the result list.</li>
  <li>If that node has a next node, push the next node into the heap.</li>
  <li>Repeat until the heap becomes empty.</li>
</ol>

<h3>Complexity</h3>

<pre>
Let N = total number of nodes
and k = number of linked lists.

TC: O(N log k)

SC: O(k)
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Min Heap / K-Way Merge</p>

<p><strong>Key Idea:</strong> Always take the smallest current head using a Min Heap.</p>
