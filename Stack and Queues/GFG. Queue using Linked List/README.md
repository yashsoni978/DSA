<h2>Queue using Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Basic-blue" alt="Difficulty: Basic"/>

<hr>

<p>Implement a <strong>Queue</strong> using a Linked List. The queue should support <code>enqueue</code>, <code>dequeue</code>, <code>getFront</code>, <code>isEmpty</code>, and <code>size</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
queries = [[1,5],[1,3],[1,4],[3],[2],[5],[4]]

<strong>Output:</strong>
[5,2,false]
</pre>

<p><strong>Approach:</strong></p>

<p>Use two pointers: <strong>front</strong> and <strong>rear</strong>.</p>

<ul>
<li><code>enqueue(x)</code> → insert a new node at the rear.</li>
<li><code>dequeue()</code> → remove the node from the front.</li>
<li><code>getFront()</code> → return <code>front-&gt;data</code>.</li>
<li><code>isEmpty()</code> → check if <code>front == nullptr</code>.</li>
<li><code>size()</code> → maintain the number of elements.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>Using both <strong>front</strong> and <strong>rear</strong> pointers makes insertion and deletion <code>O(1)</code>.</p>

<p><strong>Time Complexity:</strong> <code>O(1)</code> per operation</p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
