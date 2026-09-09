<h2>225. Implement Stack using Queues</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Implement a <strong>Stack</strong> using two <strong>Queues</strong>. The stack must support <code>push</code>, <code>pop</code>, <code>top</code>, and <code>empty</code>. </p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
push(1)
push(2)
top()
pop()
empty()

<strong>Output:</strong>
2
2
false
</pre>

<p><strong>Approach:</strong></p>

<p>Use two queues <code>q1</code> and <code>q2</code>. To simulate LIFO, when pushing a new element:</p>

<ol>
<li>Push the new element into <code>q2</code>.</li>
<li>Move all elements from <code>q1</code> into <code>q2</code>.</li>
<li>Swap <code>q1</code> and <code>q2</code>.</li>
</ol>

<p>Now the newest element is always at the <strong>front of q1</strong>, so <code>pop()</code> and <code>top()</code> become easy.</p>

<p><strong>Key Observation:</strong></p>

<p>We rearrange the queue after every <code>push</code> so that the <strong>top of the stack is always at the front of q1</strong>.</p>

<p><strong>Time Complexity:</strong> <code>push = O(n)</code>, <code>pop = O(1)</code>, <code>top = O(1)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
