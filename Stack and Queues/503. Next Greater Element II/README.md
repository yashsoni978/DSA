<h2>503. Next Greater Element II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a <strong>circular array</strong>, find the next greater element for every element. If no greater element exists, return <code>-1</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,2,1]

<strong>Output:</strong>
[2,-1,2]
</pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Monotonic Decreasing Stack</strong> and simulate the circular array by traversing the array <strong>twice</strong>.</p>

<ul>
<li>Traverse from <code>2*n - 1</code> down to <code>0</code>.</li>
<li>Use <code>i % n</code> to access the actual index.</li>
<li>Remove elements from the stack that are smaller than or equal to the current element.</li>
<li>For the first traversal of each index, store the stack top as its NGE.</li>
<li>Push the current element into the stack.</li>
</ul>

<p><strong>Key Observation:</strong></p>

<p>Since the array is <strong>circular</strong>, after the last element we continue from the first element. Traversing <code>2*n</code> times simulates this.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
