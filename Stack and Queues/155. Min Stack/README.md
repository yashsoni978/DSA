<h2>155. Min Stack</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Design a <strong>Stack</strong> that supports <code>push</code>, <code>pop</code>, <code>top</code>, and retrieving the <strong>minimum element in O(1)</strong> time. </p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
push(-2)
push(0)
push(-3)
getMin()
pop()
top()
getMin()

<strong>Output:</strong>
-3
0
-2
</pre>

<p><strong>Approach:</strong></p>

<p>Use two stacks: <code>stack</code> stores the elements and <code>minStack</code> stores the minimum value at each level.</p>

<ul>
<li><code>push(x)</code> → push <code>x</code> and <code>min(x, currentMin)</code>.</li>
<li><code>pop()</code> → pop from both stacks.</li>
<li><code>top()</code> → return the top of <code>stack</code>.</li>
<li><code>getMin()</code> → return the top of <code>minStack</code>.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>The top of <code>minStack</code> always stores the <strong>minimum element of the current stack</strong>, so <code>getMin()</code> takes <code>O(1)</code>.</p>

<p><strong>Time Complexity:</strong> <code>O(1)</code> per operation</p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
