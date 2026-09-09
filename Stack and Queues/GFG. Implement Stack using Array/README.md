<h2>Implement Stack using Array</h2>

<img src="https://img.shields.io/badge/Difficulty-Basic-blue" alt="Difficulty: Basic"/>

<hr>

<p>Implement a <strong>Stack</strong> using an array with a fixed capacity. The stack should support <code>push</code>, <code>pop</code>, <code>peek</code>, <code>isEmpty</code>, and <code>isFull</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
n = 3
queries = [[1,5],[1,3],[3],[2],[4],[5]]

<strong>Output:</strong>
[3,false,false]
</pre>

<p><strong>Approach:</strong></p>

<p>Use an array and maintain a <strong>top</strong> variable representing the index of the top element.</p>

<ul>
<li><code>push(x)</code> → increment <code>top</code> and insert <code>x</code>.</li>
<li><code>pop()</code> → remove the top element and decrement <code>top</code>.</li>
<li><code>peek()</code> → return <code>arr[top]</code>.</li>
<li><code>isEmpty()</code> → <code>top == -1</code>.</li>
<li><code>isFull()</code> → <code>top == n - 1</code>.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>The <code>top</code> pointer keeps track of the current top element and the number of elements in the stack.</p>

<p><strong>Time Complexity:</strong> <code>O(1)</code> per operation</p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
