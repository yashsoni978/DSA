<h2>160. Intersection of Two Linked Lists</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Given the heads of two singly linked lists, <code>headA</code> and <code>headB</code>, return the node at which the two lists intersect.</p>

<p>If the two linked lists do not intersect, return <code>null</code>.</p>

<p>The linked lists must retain their original structure after the function returns.</p>

<h3>Example 1</h3>

<pre>
Input:
List A: 4 -> 1 -> 8 -> 4 -> 5
List B: 5 -> 6 -> 1 -> 8 -> 4 -> 5

Output:
Intersected at node with value 8
</pre>

<h3>Example 2</h3>

<pre>
Input:
List A: 1 -> 9 -> 1 -> 2 -> 4
List B: 3 -> 2 -> 4

Output:
Intersected at node with value 2
</pre>

<h3>Example 3</h3>

<pre>
Input:
List A: 2 -> 6 -> 4
List B: 1 -> 5

Output:
null
</pre>

<h3>Approach</h3>

<ul>
<li>Use two pointers, <code>pA</code> and <code>pB</code>, starting at <code>headA</code> and <code>headB</code>.</li>
<li>Move both pointers one node at a time.</li>
<li>When <code>pA</code> reaches the end of List A, redirect it to <code>headB</code>.</li>
<li>When <code>pB</code> reaches the end of List B, redirect it to <code>headA</code>.</li>
<li>This makes both pointers travel the same total distance: <code>lengthA + lengthB</code>.</li>
<li>If the lists intersect, both pointers will meet at the intersection node.</li>
<li>If they do not intersect, both pointers will eventually become <code>null</code> at the same time.</li>
</ul>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n + m)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Linked List / Two Pointers</p>

<p><strong>Key Idea:</strong> Redirect each pointer to the other list after reaching the end, making both pointers traverse the same total distance and guaranteeing that they meet at the intersection node if one exists.</p>
