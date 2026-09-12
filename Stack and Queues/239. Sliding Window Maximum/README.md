<h2>239. Sliding Window Maximum</h2>
<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>
<hr>

<p>Given an array and a window of size <code>k</code>, return the <strong>maximum element</strong> in every sliding window.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
nums = [1,3,-1,-3,5,3,6,7], k = 3

<strong>Output:</strong>
[3,3,5,5,6,7] </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Use a <strong>Monotonic Deque</strong> storing indices. Keep indices in decreasing order of their values.</p>

<ul>
<li>Remove indices from the front if they are <strong>outside the current window</strong>.</li>
<li>Remove indices from the back while their value is <strong>smaller than the current element</strong>.</li>
<li>Push the current index.</li>
<li>Once the window reaches size <code>k</code>, the front index gives the maximum.</li>
</ul>

<p><strong>Key Observation:</strong></p>
<p>The deque always keeps the <strong>largest useful element at the front</strong>, while smaller elements behind it can be removed because they can never become the maximum while the larger element is still in the window.</p>

<pre>
Deque values → decreasing
Front → maximum
</pre>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>
<p><strong>Space Complexity:</strong> <code>O(k)</code></p>
