<h2>421. Maximum XOR of Two Numbers in an Array</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an integer array <code>nums</code>, find the maximum result of <code>nums[i] XOR nums[j]</code>, where <code>0 ≤ i, j &lt; n</code>.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
nums = [3,10,5,25,2,8]

<strong>Output:</strong>
28

<strong>Explanation:</strong>
The maximum XOR is:

5 XOR 25 = 28 </pre>

<p><strong>Approach:</strong></p>

<p>Use a <strong>Binary Trie</strong> to store the binary representation of every number.</p>

<p>Since the maximum XOR depends on the highest bits, process every number from the <strong>most significant bit (31)</strong> to the least significant bit (0).</p>

<p>While calculating XOR for a number, we try to choose the <strong>opposite bit</strong> at every position. For example, if the current bit is <code>1</code>, we prefer <code>0</code>, and if it is <code>0</code>, we prefer <code>1</code>.</p>

<p>This greedy choice maximizes the XOR because higher-order bits contribute more to the final value.</p>

<p><strong>Key Observation:</strong></p>

<p>For every bit, we should try to find the opposite bit in the Trie. If it exists, choosing it gives us a <code>1</code> at that position in the XOR.</p>

<p>If the opposite bit does not exist, we have to choose the same bit.</p>

<p><strong>Time Complexity:</strong> <code>O(32 × N)</code>, which simplifies to <code>O(N)</code>.</p>

<p><strong>Space Complexity:</strong> <code>O(32 × N)</code>, which simplifies to <code>O(N)</code>.</p>
