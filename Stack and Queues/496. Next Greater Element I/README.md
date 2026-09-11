<h2>496. Next Greater Element I</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>For each element in <code>nums1</code>, find the <strong>first greater element to its right</strong> in <code>nums2</code>. If no greater element exists, return <code>-1</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
nums1 = [4,1,2]
nums2 = [1,3,4,2]

<strong>Output:</strong>
[-1,3,-1]
</pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Monotonic Decreasing Stack</strong> while traversing <code>nums2</code> from left to right.</p>

<ul>
<li>While the stack is not empty and <code>current &gt; stack.top()</code>, current is the next greater element of the top.</li>
<li>Store this mapping in a hash map.</li>
<li>Push the current element into the stack.</li>
<li>For every element in <code>nums1</code>, get its answer from the map.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>The stack keeps elements whose <strong>next greater element has not been found yet</strong>. Each element is pushed and popped at most once.</p>

<p><strong>Time Complexity:</strong> <code>O(n + m)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
