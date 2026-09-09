<h2>Queue Using Array</h2>

<img src="https://img.shields.io/badge/Difficulty-Basic-blue" alt="Difficulty: Basic"/>

<hr>

<p>Implement a <strong>Queue</strong> using an array with a fixed capacity. The queue should support <code>enqueue</code>, <code>dequeue</code>, <code>getFront</code>, <code>getRear</code>, <code>isEmpty</code>, and <code>isFull</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
n = 3
queries = [[1,5],[1,3],[1,4],[3],[2],[5],[4]]

<strong>Output:</strong>
[5,false,4]
</pre>

<p><strong>Approach:</strong></p>

<p>Use an array with two pointers: <strong>front</strong> and <strong>rear</strong>.</p>

<ul>
<li><code>enqueue(x)</code> → insert <code>x</code> at <code>rear</code>.</li>
<li><code>dequeue()</code> → remove the element at <code>front</code>.</li>
<li><code>getFront()</code> → return the element at <code>front</code>.</li>
<li><code>getRear()</code> → return the element at <code>rear</code>.</li>
<li><code>isEmpty()</code> → check whether the queue contains no elements.</li>
<li><code>isFull()</code> → check whether the queue contains <code>n</code> elements.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>A queue follows <strong>FIFO (First In, First Out)</strong>: elements are inserted from the rear and removed from the front.</p>

<p><strong>Time Complexity:</strong> <code>O(1)</code> per operation</p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
