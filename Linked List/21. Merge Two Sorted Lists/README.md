<h2>21. Merge Two Sorted Lists</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>You are given the heads of two sorted linked lists <code>list1</code> and <code>list2</code>.</p>

<p>Merge the two lists into one sorted linked list and return the head of the merged linked list.</p>

<p>The merged list should be created by splicing together the nodes of the two given lists.</p>

<h3>Example 1</h3>

<pre>
Input:
list1 = [1,2,4]
list2 = [1,3,4]

Output:
[1,1,2,3,4,4]
</pre>

<h3>Example 2</h3>

<pre>
Input:
list1 = []
list2 = []

Output:
[]
</pre>

<h3>Example 3</h3>

<pre>
Input:
list1 = []
list2 = [0]

Output:
[0]
</pre>

<h3>Approach</h3>

<ul>
<li>Create a dummy node to simplify handling the head of the merged list.</li>
<li>Use a pointer <code>temp</code> to build the merged linked list.</li>
<li>Compare the current nodes of <code>list1</code> and <code>list2</code>.</li>
<li>Attach the smaller node to <code>temp->next</code> and move that list's pointer forward.</li>
<li>Move <code>temp</code> forward after every insertion.</li>
<li>When one list becomes <code>null</code>, attach the remaining nodes of the other list.</li>
<li>Return <code>dummy->next</code> as the head of the merged list.</li>
</ul>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n + m)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Linked List / Two Pointers</p>

<p><strong>Key Idea:</strong> Compare the current nodes of both sorted lists and repeatedly attach the smaller node to the merged list until both lists are processed.</p>
