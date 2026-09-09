<h2>232. Implement Queue using Stacks</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Implement a <strong>Queue</strong> using two <strong>Stacks</strong>. The queue should support <code>push</code>, <code>pop</code>, <code>peek</code>, and <code>empty</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
push(1)
push(2)
peek()
pop()
empty()

<strong>Output:</strong>
1
1
false
</pre>

<p><strong>Approach:</strong></p>

<p>Use two stacks: <code>input</code> and <code>output</code>.</p>

<ul>
<li><code>push(x)</code> → push <code>x</code> into <code>input</code>.</li>
<li>For <code>pop()</code> or <code>peek()</code>, if <code>output</code> is empty, move all elements from <code>input</code> to <code>output</code>.</li>
<li>This reversal makes the oldest element available at the top of <code>output</code>.</li>
<li><code>empty()</code> → both stacks must be empty.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>Moving elements from one stack to another <strong>reverses their order</strong>, converting LIFO behavior into FIFO behavior.</p>

<p><strong>Time Complexity:</strong> <code>push = O(1)</code>, <code>pop/peek = O(1)</code> amortized</p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
