<h2>Array to Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<p>We need to convert each element of the array into a <strong>node</strong> of a singly linked list while maintaining the same order.</p>

<pre>
Array:

[1, 2, 3, 4, 5]

        ↓

Linked List:

1 → 2 → 3 → 4 → 5 → NULL
</pre>

<h3>Approach</h3>

<ul>
<li>Create a new node for every array element.</li>
<li>The first node becomes the <strong>head</strong>.</li>
<li>Maintain a pointer <code>tail</code> to the last node.</li>
<li>For every new node, connect <code>tail-&gt;next</code> to it.</li>
<li>Move <code>tail</code> to the newly created node.</li>
<li>Finally, return <code>head</code>.</li>
</ul>

<h3>Example</h3>

<pre>
arr = [10, 20, 30]

Initially:

head = NULL
tail = NULL

Create 10:

head
 ↓
10 → NULL
 ↑
tail

Create 20:

head
 ↓
10 → 20 → NULL
      ↑
     tail

Create 30:

head
 ↓
10 → 20 → 30 → NULL
           ↑
          tail
</pre>

<h3>Key Idea</h3>

<pre>
First element
     ↓
   HEAD

Every next element
     ↓
Create Node
     ↓
tail → newNode
     ↓
tail = newNode
</pre>

<p>The <strong>head never changes</strong> after the first node. The <code>tail</code> keeps moving forward as new nodes are added.</p>

<h3>Complexity</h3>

<pre>
TC: O(n)

Each array element is processed once.

SC: O(n)

We create n linked-list nodes.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Array Traversal / Node Creation</p>

<p><strong>Key Idea:</strong> Create one node for each array element and use a <code>tail</code> pointer to continuously append the new node to the end of the linked list.</p>
