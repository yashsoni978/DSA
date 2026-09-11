<h2>Previous Smaller Element</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>For every element, find the <strong>first strictly smaller element to its left</strong>. If no such element exists, return <code>-1</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
arr = [1, 6, 2]

<strong>Output:</strong>
[-1, 1, 1]
</pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Monotonic Increasing Stack</strong> while traversing from left to right.</p>

<ul>
<li>While the stack is not empty and <code>st.top() &gt;= arr[i]</code>, pop it.</li>
<li>If the stack is empty, PSE is <code>-1</code>.</li>
<li>Otherwise, <code>st.top()</code> is the previous smaller element.</li>
<li>Push <code>arr[i]</code> into the stack.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>Remove all elements that are <strong>greater than or equal to</strong> the current element. The remaining stack top is the nearest strictly smaller element.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
