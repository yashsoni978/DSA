<h2>907. Sum of Subarray Minimums</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an array, find the <strong>sum of the minimum value of every subarray</strong>. Return the answer modulo <code>10^9 + 7</code>.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
arr = [3,1,2,4]

<strong>Output:</strong>
17 </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Use a <strong>Monotonic Stack</strong>. For every element <code>arr[i]</code>, calculate how many subarrays have it as their minimum.</p>

<ul>
<li><strong>Previous Smaller Element (PSE)</strong> → distance to the left.</li>
<li><strong>Next Smaller Element (NSE)</strong> → distance to the right.</li>
</ul>

<pre>
Contribution = arr[i] × left × right
</pre>

<p>Where:</p>
<pre>
left  = i - PSE
right = NSE - i
</pre>

<p><strong>Key Observation:</strong></p>
<p>Instead of finding the minimum of every subarray, count how many subarrays each element contributes its value to.</p>

<p><strong>Important:</strong> With duplicate values, use different strictness on the two sides (for example, <code>&gt;</code> on one side and <code>&gt;=</code> on the other) to avoid counting the same subarray twice.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>
<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
