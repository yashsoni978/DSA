<h2>Stack using Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Basic-blue" alt="Difficulty: Basic"/>

<hr>

<p>Implement a <strong>Stack</strong> using a Linked List. The stack should support <code>push</code>, <code>pop</code>, <code>peek</code>, <code>isEmpty</code>, and <code>size</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
queries = [[1,5],[1,3],[1,4],[3],[2],[5],[4]]

<strong>Output:</strong>
[4,2,false]
</pre>

<p><strong>Approach:</strong></p>

<p>Use the <strong>head</strong> of the linked list as the top of the stack.</p>

<ul>
<li><code>push(x)</code> → create a new node and insert it at the head.</li>
<li><code>pop()</code> → remove the head node.</li>
<li><code>peek()</code> → return the value of the head node.</li>
<li><code>isEmpty()</code> → check if <code>head == nullptr</code>.</li>
<li><code>size()</code> → maintain a variable storing the number of elements.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>Inserting and deleting at the <strong>head</strong> gives <code>O(1)</code> time for both <code>push</code> and <code>pop</code>.</p>

<p><strong>Time Complexity:</strong> <code>O(1)</code> per operation</p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
