<h2>2104. Sum of Subarray Ranges</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an array, return the <strong>sum of the range</strong> of every subarray, where range = <code>maximum - minimum</code>.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
nums = [1,2,3]

<strong>Output:</strong>
4 </pre>

<p><strong>Optimal Approach:</strong></p>
<p>Break the answer into two parts:</p>

<pre>
Sum of Subarray Ranges
= Sum of Subarray Maximums
- Sum of Subarray Minimums
</pre>

<p>Use <strong>Monotonic Stacks</strong> to calculate how many subarrays each element contributes as a maximum and as a minimum.</p>

<ul>
<li>For <strong>minimums</strong> → use Previous/Next Smaller Elements.</li>
<li>For <strong>maximums</strong> → use Previous/Next Greater Elements.</li>
<li>Contribution of <code>nums[i]</code> = <code>nums[i] × left × right</code>.</li>
</ul>

<p><strong>Key Observation:</strong></p>
<p>Instead of calculating every subarray range, count each element's contribution as a <strong>minimum</strong> and as a <strong>maximum</strong>.</p>

<pre>
Answer = Total Maximum Contribution
       - Total Minimum Contribution
</pre>

<p><strong>Important:</strong> Handle duplicate elements carefully by using different strictness (<code>&gt;</code>/<code>&gt;=</code> and <code>&lt;</code>/<code>&lt;=</code>) on the two sides.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>
<p><strong>Space Complexity:</strong> <code>O(n)</code></p>
